/* 
 * File:   mcal_external_interrupt.c
 * Author: Yossri
 *
 * Created on July 20, 2023, 1:27 AM
 */
#include "mcal_external_interrupt.h"

/*pointer to function point to ISR function in a high level layer (call back function)*/
static interruptHandler INT0_interruptHandler = NULL;
static interruptHandler INT1_interruptHandler = NULL;
static interruptHandler INT2_interruptHandler = NULL;

static interruptHandler RB4_interruptHandler_High = NULL;
static interruptHandler RB4_interruptHandler_Low = NULL;
static interruptHandler RB5_interruptHandler_High = NULL;
static interruptHandler RB5_interruptHandler_Low = NULL;
static interruptHandler RB6_interruptHandler_High = NULL;
static interruptHandler RB6_interruptHandler_Low = NULL;
static interruptHandler RB7_interruptHandler_High = NULL;
static interruptHandler RB7_interruptHandler_Low = NULL;
/*=============================================================================================*/

static Std_ReturnType Interrupt_INTX_Enable(const EXT_INTX_t *int_obj);
static Std_ReturnType Interrupt_INTX_Disable(const EXT_INTX_t *int_obj);

static Std_ReturnType Interrupt_INTX_Edge_Intiat(const EXT_INTX_t *int_obj);
static Std_ReturnType Interrupt_INTX_Pin_Intiat(const EXT_INTX_t *int_obj);

static Std_ReturnType Interrupt_INTX_Clear_Flag(const EXT_INTX_t *int_obj);

static Std_ReturnType Set_INT0_Handler(void (*INTX_interruptHandler) (void));
static Std_ReturnType Set_INT1_Handler(void (*INTX_interruptHandler) (void));
static Std_ReturnType Set_INT2_Handler(void (*INTx_interruptHandler) (void));
static Std_ReturnType Set_INTX_Handler(const EXT_INTX_t *int_obj);

static Std_ReturnType Interrupt_RBX_Enable(const EXT_RBX_t *int_obj);
static Std_ReturnType Interrupt_RBX_Disable(const EXT_RBX_t *int_obj);

static Std_ReturnType Interrupt_RBX_Priority_Intiat(const EXT_RBX_t *int_obj);
static Std_ReturnType Interrupt_RBX_Pin_Intiat(const EXT_RBX_t *int_obj);
static Std_ReturnType Set_RBX_Handler(const EXT_RBX_t *int_obj);


/**

@brief Initializes an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
Std_ReturnType EXT_INTX_Intialize(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_NOT_OK ;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        /*disable int*/
        ret = Interrupt_INTX_Disable(int_obj);
        /*clear flag*/
        ret |= Interrupt_INTX_Clear_Flag(int_obj);
        /*set edge*/
        ret |= Interrupt_INTX_Edge_Intiat(int_obj);
        /*set i/o pin*/
        ret |= Interrupt_INTX_Pin_Intiat(int_obj);
        /*set call back function*/
        ret |= Set_INTX_Handler(int_obj);
        /*Enable int & set priority if found*/ 
        ret |= Interrupt_INTX_Enable(int_obj);
    }
    return ret;
}

void INT0_ISR(void)
{
    /*Clear Flag*/
    EXT_INTERRUPT_INT0_Clear_Flag();
    /*code*/
    
    /* call back function*/
    if(NULL == INT0_interruptHandler)
    {/*Nothing*/}
    else
    {
        INT0_interruptHandler();
    }
}

void INT1_ISR(void)
{
    /*Clear Flag*/
    EXT_INTERRUPT_INT1_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(NULL == INT1_interruptHandler)
    {/*Nothing*/} 
    else
    {
        INT1_interruptHandler();
    }
}

void INT2_ISR(void)
{
    /*Clear Flag*/
    EXT_INTERRUPT_INT2_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(NULL == INT2_interruptHandler)
    {/*Nothing*/}
    else
    {
        INT2_interruptHandler();
    }
}

/**

@brief DE Initializes an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
Std_ReturnType EXT_INTX_DE_Intialize(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = Interrupt_INTX_Disable(int_obj);
    }
    return ret;
}

/**

@brief Initializes an RB port external interrupt with the given configuration settings
specified in the EXT_RBX_t structure pointed to by @p int_obj. The function performs
@param[in] int_obj Pointer to an EXT_RBX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
Std_ReturnType EXT_RBX_Intialize(const EXT_RBX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        /*disable int*/
        EXT_INTERRUPT_RBX_Disable();
        /*clear flag*/
        EXT_INTERRUPT_RBX_Clear_Flag();
        
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
        /*set priority*/
        ret = Interrupt_RBX_Priority_Intiat(int_obj);
#else
        INTERRUPT_AllInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        /*set i/o pin*/
        ret = Interrupt_RBX_Pin_Intiat(int_obj);
        /*set call back function*/
        Set_RBX_Handler(int_obj);
        /*Enable int*/
        EXT_INTERRUPT_RBX_Enable();
    }
    return ret;
}

void RB4_ISR(uint8 state)
{
    /*Clear Flag*/
    EXT_INTERRUPT_RBX_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(0 == state)
    {
        if (NULL == RB4_interruptHandler_High) {
            /*Nothing*/
        } else {
            RB4_interruptHandler_High();
        }
    }
    else if(1 == state)
    {
        if (NULL == RB4_interruptHandler_Low) {
            /*Nothing*/
        } else {
            RB4_interruptHandler_Low();
        }
    }else {/*Nothing*/}
    
}
void RB5_ISR(uint8 state)
{
   /*Clear Flag*/
    EXT_INTERRUPT_RBX_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(0 == state)
    {
        if (NULL == RB5_interruptHandler_High) {
            /*Nothing*/
        } else {
            RB5_interruptHandler_High();
        }
    }
    else if(1 == state)
    {
        if (NULL == RB5_interruptHandler_Low) {
            /*Nothing*/
        } else {
            RB5_interruptHandler_Low();
        }
    }else {/*Nothing*/}
}
void RB6_ISR(uint8 state)
{
    /*Clear Flag*/
    EXT_INTERRUPT_RBX_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(0 == state)
    {
        if (NULL == RB6_interruptHandler_High) {
            /*Nothing*/
        } else {
            RB6_interruptHandler_High();
        }
    }
    else if(1 == state)
    {
        if (NULL == RB6_interruptHandler_Low) {
            /*Nothing*/
        } else {
            RB6_interruptHandler_Low();
        }
    }else {/*Nothing*/}
}
void RB7_ISR(uint8 state)
{
     /*Clear Flag*/
    EXT_INTERRUPT_RBX_Clear_Flag();
    /*code*/
    
    /*set call back function*/
    if(0 == state)
    {
        if (NULL == RB7_interruptHandler_High) {
            /*Nothing*/
        } else {
            RB7_interruptHandler_High();
        }
    }
    else if(1 == state)
    {
        if (NULL == RB7_interruptHandler_Low) {
            /*Nothing*/
        } else {
            RB7_interruptHandler_Low();
        }
    }else {/*Nothing*/}
}

/**

@brief Enable an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_INTX_Enable(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(int_obj->source)
        {
            case EXT_INT0:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_HighPriorityEnable();
#else
                INTERRUPT_AllInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INTERRUPT_INT0_Enable();
                break;
            case EXT_INT1:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_PriorityLevelsEnable();
                if(High_Priority == int_obj->priority){
                    INTERRUPT_HighPriorityEnable();
                    EXT_INTERRUPT_INT1_Priority_High();/*set priority high*/
                }
                else if(Low_Priority == int_obj->priority){
                    INTERRUPT_LowPriorityEnable();
                    EXT_INTERRUPT_INT1_Priority_Low();/*set priority low*/
                }
                else {/*Nothing*/}
#else
                INTERRUPT_AllInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INTERRUPT_INT1_Enable();
                break;
            case EXT_INT2:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_PriorityLevelsEnable();
                if(Priority == int_obj->priority){
                    INTERRUPT_HighPriorityEnable();
                    EXT_INTERRUPT_INT2_Priority_High();
                }
                else if(Low_Priority == int_obj->priority){
                    INTERRUPT_LowPriorityEnable();
                    EXT_INTERRUPT_INT2_Priority_Low();
                }
                else {/*Nothing*/}
#else
                INTERRUPT_AllInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INTERRUPT_INT2_Enable();
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
/**

@brief Disable an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_INTX_Disable(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(int_obj->source)
        {
            case EXT_INT0:
                EXT_INTERRUPT_INT0_Disable();
                break;
            case EXT_INT1:
                EXT_INTERRUPT_INT1_Disable();
                break;
            case EXT_INT2:
                EXT_INTERRUPT_INT2_Disable();
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
/**

@brief Set Edge for an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_INTX_Edge_Intiat(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(int_obj->source)
        {
            case EXT_INT0:
                if(EXT_INT_Faling_Edge == int_obj->edge){EXT_INTERRUPT_INT0_Falling_Edge();}
                else if(EXT_INT_Raising_Edge == int_obj->edge){EXT_INTERRUPT_INT0_Rising_Edge();}
                else {/*Nothing*/}
                break;
            case EXT_INT1:
                if(EXT_INT_Faling_Edge == int_obj->edge){EXT_INTERRUPT_INT1_Falling_Edge();}
                else if(EXT_INT_Raising_Edge == int_obj->edge){EXT_INTERRUPT_INT1_Rising_Edge();}
                else {/*Nothing*/}
                break;
            case EXT_INT2:
                if(EXT_INT_Faling_Edge == int_obj->edge){EXT_INTERRUPT_INT2_Falling_Edge();}
                else if(EXT_INT_Raising_Edge == int_obj->edge){EXT_INTERRUPT_INT2_Rising_Edge();}
                else {/*Nothing*/}
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
/**

@brief intialize pin for an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_INTX_Pin_Intiat(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret =GPIO_Pin_Direction_Intialize(&(int_obj->EXT_pin));
    }
    return ret;
}
/**

@brief clear flag for an external interrupt with the given configuration settings
specified in the EXT_INTX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_INTX_Clear_Flag(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(int_obj->source)
        {
            case EXT_INT0:
                EXT_INTERRUPT_INT0_Clear_Flag();
                break;
            case EXT_INT1:
                EXT_INTERRUPT_INT1_Clear_Flag();
                break;
            case EXT_INT2:
                EXT_INTERRUPT_INT2_Clear_Flag();
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
/**

@brief Sets the callback function for the INT0 external interrupt.
This function sets the callback function for the INT0 external interrupt to the function
specified by @p INTX_interruptHandler.
@param[in] INTX_interruptHandler Pointer to the function that will handle INT0 external interrupt.
@return Status of the function execution.
@retval E_OK The callback function was successfully set.
@retval E_NOT_OK Failed to set the callback function (i.e., the @p INTX_interruptHandler parameter was NULL).
*/
static Std_ReturnType Set_INT0_Handler(void (*INTX_interruptHandler) (void))
{
    Std_ReturnType ret = E_OK;
    if(INTX_interruptHandler == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        INT0_interruptHandler = INTX_interruptHandler;
    }
    return ret;
}
/**

@brief Sets the callback function for the INT1 external interrupt.
This function sets the callback function for the INT0 external interrupt to the function
specified by @p INTX_interruptHandler.
@param[in] INTX_interruptHandler Pointer to the function that will handle INT0 external interrupt.
@return Status of the function execution.
@retval E_OK The callback function was successfully set.
@retval E_NOT_OK Failed to set the callback function (i.e., the @p INTX_interruptHandler parameter was NULL).
*/
static Std_ReturnType Set_INT1_Handler(void (*INTX_interruptHandler) (void))
{
     Std_ReturnType ret = E_OK;
    if(INTX_interruptHandler == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        INT1_interruptHandler = INTX_interruptHandler;
    }
    return ret;
}
/**

@brief Sets the callback function for the INT2 external interrupt.
This function sets the callback function for the INT0 external interrupt to the function
specified by @p INTX_interruptHandler.
@param[in] INTX_interruptHandler Pointer to the function that will handle INT0 external interrupt.
@return Status of the function execution.
@retval E_OK The callback function was successfully set.
@retval E_NOT_OK Failed to set the callback function (i.e., the @p INTX_interruptHandler parameter was NULL).
*/
static Std_ReturnType Set_INT2_Handler(void (*INTx_interruptHandler) (void))
{
     Std_ReturnType ret = E_OK;
    if(INTx_interruptHandler == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        INT2_interruptHandler = INTx_interruptHandler;
    }
    return ret;
}
/**

@brief Sets the callback function for the specified external interrupt.
This function sets the callback function for the external interrupt specified by the @p int_obj parameter.
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The callback function was successfully set.
@retval E_NOT_OK Failed to set the callback function (i.e., the @p int_obj parameter was NULL or the @p source value was invalid).
*/
static Std_ReturnType Set_INTX_Handler(const EXT_INTX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(int_obj->source)
        {
            case EXT_INT0:
                Set_INT0_Handler(int_obj->Interrupt_Handler);
                break;
            case EXT_INT1:
                Set_INT1_Handler(int_obj->Interrupt_Handler);
                break;
            case EXT_INT2:
                Set_INT2_Handler(int_obj->Interrupt_Handler);
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
/**

@brief Set Priority for an external interrupt RBX with the given configuration settings
specified in the EXT_RBX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
static Std_ReturnType Interrupt_RBX_Priority_Intiat(const EXT_RBX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
         if(High_Priority == int_obj->priority)
        {
            INTERRUPT_HighPriorityEnable();
            EXT_INTERRUPT_RBX_Priority_High();
        }
        else if(Low_Priority == int_obj->priority)
        {
            INTERRUPT_LowPriorityEnable();
            EXT_INTERRUPT_RBX_Priority_Low();
        }
    }
    return ret;
}
#endif
/**

@brief intialize pin for an external interrupt RBX with the given configuration settings
specified in the EXT_RBX_t structure pointed to by @p int_obj
@param[in] int_obj Pointer to an EXT_INTX_t structure containing the interrupt configuration settings.
@return Status of the function execution.
@retval E_OK The interrupt was successfully initialized.
@retval E_NOT_OK Failed to initialize the interrupt.
*/
static Std_ReturnType Interrupt_RBX_Pin_Intiat(const EXT_RBX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret =GPIO_Pin_Intialize(&(int_obj->EXT_pin));
    }
    return ret;
}


static Std_ReturnType Set_RBX_Handler(const EXT_RBX_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL ) 
    {
        ret = E_NOT_OK ;
    }
    else
    {
         switch(int_obj->EXT_pin.pin)
        {
            case pin4:
                RB4_interruptHandler_High = int_obj->Interrupt_Handler_High;
                RB4_interruptHandler_Low  = int_obj->Interrupt_Handler_Low;
                break;
            case pin5:
                RB5_interruptHandler_High = int_obj->Interrupt_Handler_High;
                RB5_interruptHandler_Low  = int_obj->Interrupt_Handler_Low;
                break;
            case pin6:
                RB6_interruptHandler_High = int_obj->Interrupt_Handler_High;
                RB6_interruptHandler_Low  = int_obj->Interrupt_Handler_Low;
                break;
            case pin7:
                RB7_interruptHandler_High = int_obj->Interrupt_Handler_High;
                RB7_interruptHandler_Low  = int_obj->Interrupt_Handler_Low;
                break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}


