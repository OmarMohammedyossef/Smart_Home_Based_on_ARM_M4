/*
  =============================================================================
 * Name		:GPIO_programe.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
#include "../../LIB/state_errors.h"
#include "../../LIB/STD_datatypes.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
/* each function take port name and pin number and another parameters*/
/* this function take pin mode and does this pin pull up or pull down*/
ES_t MGPIO_enumselect_pin_mode(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8pin_mode,u8 copy_u8pullup_down){
   ES_t state_error =ES_NOK;

      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)&&(copy_u8pin_mode<=GPIO_ANALOG)&&(copy_u8pullup_down<=GPIO_PULL_DOWN))
      {
    	  /* check if GPIO peripheral not enable */
    	  if(copy_u8port_name!=GPIOH){
    	       if(!(read_bit(RCC_AHB1ENR,copy_u8port_name))){
    		      state_error = ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    		      return state_error;
    	       }
    	  }
    	  else{

    		  if(!(read_bit(RCC_AHB1ENR,7))){
    		     state_error = ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    		     return state_error;
    		  }
    	  }
    	  /*********************************************************************/
              if(copy_u8port_name==GPIOH){
    	      	 if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),copy_u8pin_id)){
    	      	   	if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK)){

    	      	        	state_error =ES_GPIO_LOCKED_PORTH_AND_PIN;
    	      	   	}
    	      	   	else{
    	      	   	        state_error =ES_GPIO_LOCKED_PIN_H;
    	      	    }


    	      	 }
    	      	 else{
    	      			    GPIO->GPIO_registers[copy_u8port_name+GPIO_MODER]&=~(((u32)3)<<(copy_u8pin_id*2));
    	      			    GPIO->GPIO_registers[copy_u8port_name+GPIO_MODER]|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	      		        GPIO->GPIO_registers[copy_u8port_name+GPIO_PUPDR]&=~(((u32)3)<<(copy_u8pin_id*2));
    	      		        GPIO->GPIO_registers[copy_u8port_name+GPIO_PUPDR]|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	      	            state_error =ES_OK;
    	           }
    	      }
    	      else{
    	            /*here other ports*/
    	          if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),copy_u8pin_id)){
    	            	if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK)){
    	                 switch (copy_u8port_name)
    	                 {
    	                      case   GPIOA:  state_error =ES_GPIO_LOCKED_PORTA_AND_PIN; break;
    	                      case   GPIOB:  state_error =ES_GPIO_LOCKED_PORTB_AND_PIN; break;
    	                      case   GPIOC:  state_error =ES_GPIO_LOCKED_PORTC_AND_PIN; break;
    	                      case   GPIOD:  state_error =ES_GPIO_LOCKED_PORTD_AND_PIN; break;
    	                      case   GPIOE:  state_error =ES_GPIO_LOCKED_PORTE_AND_PIN; break;
    	                      default:      break;
    	                 }
    	            	}
    	            	else{

    	            		switch (copy_u8port_name)
    	            		{
    	            	         case   GPIOA:  state_error =ES_GPIO_LOCKED_PIN_A; break;
    	            		     case   GPIOB:  state_error =ES_GPIO_LOCKED_PIN_B; break;
    	            		     case   GPIOC:  state_error =ES_GPIO_LOCKED_PIN_C; break;
    	            		     case   GPIOD:  state_error =ES_GPIO_LOCKED_PIN_D; break;
    	            		     case   GPIOE:  state_error =ES_GPIO_LOCKED_PIN_E; break;
    	            		     default:      break;
    	            		}
    	             }
    	          }
    	          else{

    	          	     GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_MODER]&=~(((u32)3)<<(copy_u8pin_id*2));
    	          	     GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_MODER]|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	                 GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_PUPDR]&=~(((u32)3)<<(copy_u8pin_id*2));
    	                 GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_PUPDR]|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	                 state_error =ES_OK;

    	         }

    	      }
            }
    	     else{
    	   	  state_error =ES_OUT_OF_RANGE;
    	     }
    	 return state_error;


  /* if(((copy_u8port_name>=GPIO_PORT_A)&&(copy_u8port_name<=GPIO_PORT_H))&&((copy_u8pin_id>=GPIO_PIN_0)&&(copy_u8pin_id<=GPIO_PIN_15))&&((copy_u8pin_mode>=GPIO_INPUT)&&(copy_u8pin_mode<=GPIO_ANALOG))&&((copy_u8pullup_down>=GPIO_FLOATING)&&(copy_u8pullup_down<=GPIO_PULL_DOWN)))
   {
	   switch(copy_u8port_name){

    	     case  GPIO_PORT_A: if(read_bit(RCC_AHB1ENR,GPIO_PORT_A)){
    	                    	    if(read_bit((GPIOA->LCKR),copy_u8pin_id)){
    	                    	    	if(read_bit((GPIOA->LCKR),LCKK)){

    	                    	    		state_error =ES_GPIO_LOCKED_PORTA_AND_PIN;
    	                    	    	}
    	                    	    	else{
    	                    		       state_error =ES_GPIO_LOCKED_PIN;
    	                    	    	}
    	                    	    }
    	                    	    else{
    	    	                       GPIOA->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                       GPIOA->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	                       GPIOA->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                       GPIOA->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	                       state_error =ES_OK;
    	                    	    }
    	                        }
    	                        else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	   	                    break;
    	     case  GPIO_PORT_B: if(read_bit(RCC_AHB1ENR,GPIO_PORT_B)){
    	    	                        if(read_bit((GPIOB->LCKR),copy_u8pin_id)){
    	    	     	                   if(read_bit((GPIOB->LCKR),LCKK)){

    	    	     	                      state_error =ES_GPIO_LOCKED_PORTB_AND_PIN;
    	    	     	                   }
    	    	     	                   else{
    	    	     	                    		 state_error =ES_GPIO_LOCKED_PIN;
    	    	     	                   }
    	    	     	                 }
    	    	     	                 else{
    	                                    GPIOB->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	     	    	            GPIOB->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	     	    	            GPIOB->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	     	    	            GPIOB->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	     	    	            state_error =ES_OK;
    	    	     	                 }
    	                        }
    	                        else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	   	                    break;
    	     case  GPIO_PORT_C: if(read_bit(RCC_AHB1ENR,GPIO_PORT_C)){
    	    	                      if(read_bit((GPIOC->LCKR),copy_u8pin_id)){
    	    	     	                    if(read_bit((GPIOC->LCKR),LCKK)){
    	    	     	                       state_error =ES_GPIO_LOCKED_PORTC_AND_PIN;
    	    	     	                     }
    	    	     	                     else{
    	    	     	                       state_error =ES_GPIO_LOCKED_PIN;
    	    	     	                   	 }
    	    	     	              }
    	    	     	          else{
    	    	                       GPIOC->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                       GPIOC->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	                       GPIOC->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                       GPIOC->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	                       state_error =ES_OK;
    	                          }
    	                       }
    	                       else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	   	                    break;
    	     case  GPIO_PORT_D: if(read_bit(RCC_AHB1ENR,GPIO_PORT_D)){
    	    	                    if(read_bit((GPIOD->LCKR),copy_u8pin_id)){
    	    	                          if(read_bit((GPIOD->LCKR),LCKK)){
    	    	                             state_error =ES_GPIO_LOCKED_PORTD_AND_PIN;
    	    	                           }
    	    	                           else{
    	    	                             state_error =ES_GPIO_LOCKED_PIN;
    	    	                         	 }
    	    	                    }
    	    	                    else{
    	    	                           GPIOD->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                           GPIOD->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	                           GPIOD->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                           GPIOD->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	                           state_error =ES_OK;
    	                            }
    	                         }
    	                        else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	   	                    break;
    	     case  GPIO_PORT_E: if(read_bit(RCC_AHB1ENR,GPIO_PORT_E)){
    	    	                    if(read_bit((GPIOE->LCKR),copy_u8pin_id)){
    	    	                        if(read_bit((GPIOE->LCKR),LCKK)){
    	    	                          state_error =ES_GPIO_LOCKED_PORTE_AND_PIN;
    	    	                         }
    	    	                         else{
    	    	                           state_error =ES_GPIO_LOCKED_PIN;
    	    	         	             }
    	    	                     }
    	                             else{
    	    	                        GPIOE->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                        GPIOE->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	                        GPIOE->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                        GPIOE->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	                        state_error =ES_OK;
    	                             }
    	                        }
    	                        else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	    	                break;
    	     case  GPIO_PORT_H: if(read_bit(RCC_AHB1ENR,(GPIO_PORT_H+2))){
    	                        	    if(read_bit((GPIOH->LCKR),copy_u8pin_id)){
    	                        	          if(read_bit((GPIOH->LCKR),LCKK)){
    	                        	             state_error =ES_GPIO_LOCKED_PORTH_AND_PIN;
    	                        	           }
    	                        	           else{
    	                        	             state_error =ES_GPIO_LOCKED_PIN;
    	                        	         	 }
    	                        	    }
    	                        	    else{
    	    	                           GPIOH->MODER&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                           GPIOH->MODER|=(((u32)copy_u8pin_mode)<<(copy_u8pin_id*2));
    	    	                           GPIOH->PUPDR&=~(((u32)3)<<(copy_u8pin_id*2));
    	    	                           GPIOH->PUPDR|=(((u32)copy_u8pullup_down)<<(copy_u8pin_id*2));
    	    	                           state_error =ES_OK;
    	                                }
    	                        }

    	                        else{
    	                        	state_error=ES_GPIO_PERPHEIRAL_NOT_ENABLE;
    	                        }
    	   	                    break;

    	     default          :                    break;

    	     }
    	     }
    	     else{
    	     state_error =ES_OUT_OF_RANGE;
    	     }
    	 return state_error;*/

////////////////////////////////////////////////////////////////////////////////////////////////////

}

/*this function take output type and output speed*/

ES_t MGPIO_enumselect_output_type(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8output_type,u8 copy_u8pin_speed){
	ES_t state_error =ES_NOK;
	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)&&(copy_u8output_type<=GPIO_OPEN_DRAIN)&&(copy_u8pin_speed<=GPIO_VERY_HIGH_SPEED))
	      {
              if(copy_u8port_name==GPIOH){
	    	  	 if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),copy_u8pin_id)){
              	   	if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK)){

	    	  	        	state_error =ES_GPIO_LOCKED_PORTH_AND_PIN;

	    	  	   	}
	    	  	   	else{

	    	  	   	        state_error =ES_GPIO_LOCKED_PIN_H;

	    	  	   	}
	    	  	 }
	    	  	 else{
	    	  			    GPIO->GPIO_registers[copy_u8port_name+GPIO_OTYPER]&=~(((u32)1)<<(copy_u8pin_id));
	    	  			    GPIO->GPIO_registers[copy_u8port_name+GPIO_OTYPER]|=(((u32)copy_u8output_type)<<(copy_u8pin_id));
	    	  		        GPIO->GPIO_registers[copy_u8port_name+GPIO_OSPEEDR]&=~(((u32)3)<<(copy_u8pin_id*2));
	    	  		        GPIO->GPIO_registers[copy_u8port_name+GPIO_OSPEEDR]|=(((u32)copy_u8pin_speed)<<(copy_u8pin_id*2));
	    	  	            state_error =ES_OK;

	    	       }
	    	  }
	    	  else{
	    	        /*here other ports*/
	    	      if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),copy_u8pin_id)){
	    	        	if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK)){
	    	             switch (copy_u8port_name)
                         {
	    	                  case   GPIOA:  state_error =ES_GPIO_LOCKED_PORTA_AND_PIN; break;
	    	                  case   GPIOB:  state_error =ES_GPIO_LOCKED_PORTB_AND_PIN; break;
	    	                  case   GPIOC:  state_error =ES_GPIO_LOCKED_PORTC_AND_PIN; break;
                              case   GPIOD:  state_error =ES_GPIO_LOCKED_PORTD_AND_PIN; break;
	    	                  case   GPIOE:  state_error =ES_GPIO_LOCKED_PORTE_AND_PIN; break;
	    	                  default:      break;
	    	             }
	    	        	}
	    	        	else{

	    	        		switch (copy_u8port_name)
	    	        		{
	    	        		     case   GPIOA:  state_error =ES_GPIO_LOCKED_PIN_A; break;
	    	        		     case   GPIOB:  state_error =ES_GPIO_LOCKED_PIN_B; break;
	    	        		     case   GPIOC:  state_error =ES_GPIO_LOCKED_PIN_C; break;
	    	        		     case   GPIOD:  state_error =ES_GPIO_LOCKED_PIN_D; break;
	    	        		     case   GPIOE:  state_error =ES_GPIO_LOCKED_PIN_E; break;
	    	        		     default:      break;
	    	        		}
                     }
	    	      }
	    	      else{

	    	      	     GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_OTYPER]&=~(((u32)1)<<(copy_u8pin_id));
	    	      	     GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_OTYPER]|=(((u32)copy_u8output_type)<<(copy_u8pin_id));
	    	             GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_OSPEEDR]&=~(((u32)3)<<(copy_u8pin_id*2));
	    	             GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_OSPEEDR]|=(((u32)copy_u8pin_speed)<<(copy_u8pin_id*2));
	    	             state_error =ES_OK;

	    	     }

	    	  }
	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}



/*this function take alternate function name*/
ES_t MGPIO_enumselect_alternate_fun(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8alternate_name){
	   ES_t state_error =ES_NOK;
	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)&&(copy_u8alternate_name<=GPIO_AF15_EVENTOUT))
	      {
               if(copy_u8port_name==GPIOH){
            		 if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),copy_u8pin_id)){
            		   	if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK)){

            		        	state_error =ES_GPIO_LOCKED_PORTH_AND_PIN;

            		   	}
            		   	else{

            		   	        state_error =ES_GPIO_LOCKED_PIN_H;

            		   	}
            		 }
            		 else{
            			  if(copy_u8pin_id<=7){
            				    GPIO->GPIO_registers[copy_u8port_name+GPIO_AFRL]&=~(((u32)15)<<(copy_u8pin_id*4));
            				    GPIO->GPIO_registers[copy_u8port_name+GPIO_AFRL]|=(((u32)copy_u8alternate_name)<<(copy_u8pin_id*4));
            				    state_error =ES_OK;
            			  }
            			  else{
            				   copy_u8pin_id=copy_u8pin_id-8;
            			       GPIO->GPIO_registers[copy_u8port_name+GPIO_AFRH]&=~(((u32)15)<<(copy_u8pin_id*4));
            			       GPIO->GPIO_registers[copy_u8port_name+GPIO_AFRH]|=(((u32)copy_u8alternate_name)<<(copy_u8pin_id*4));
            		           state_error =ES_OK;
            			  }
            	     }
               }
               else{
            	      /*here other ports*/
            	    if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),copy_u8pin_id)){
            	      	if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK)){
            	           switch (copy_u8port_name)
            	           {
            	                case   GPIOA:  state_error =ES_GPIO_LOCKED_PORTA_AND_PIN; break;
            	                case   GPIOB:  state_error =ES_GPIO_LOCKED_PORTB_AND_PIN; break;
            	                case   GPIOC:  state_error =ES_GPIO_LOCKED_PORTC_AND_PIN; break;
            	                case   GPIOD:  state_error =ES_GPIO_LOCKED_PORTD_AND_PIN; break;
            	                case   GPIOE:  state_error =ES_GPIO_LOCKED_PORTE_AND_PIN; break;
            	                default:      break;
            	           }
            	      	}
            	      	else{

            	      		switch (copy_u8port_name)
            	      		{
            	      		     case   GPIOA:  state_error =ES_GPIO_LOCKED_PIN_A; break;
            	      		     case   GPIOB:  state_error =ES_GPIO_LOCKED_PIN_B; break;
            	      		     case   GPIOC:  state_error =ES_GPIO_LOCKED_PIN_C; break;
            	      		     case   GPIOD:  state_error =ES_GPIO_LOCKED_PIN_D; break;
            	      		     case   GPIOE:  state_error =ES_GPIO_LOCKED_PIN_E; break;
            	      		     default:      break;
            	      		}
            	       }
            	    }
            	    else{
            	      if(copy_u8pin_id<=7){
            	    	    GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_AFRL]&=~(((u32)15)<<(copy_u8pin_id*4));
            	    	    GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_AFRL]|=(((u32)copy_u8alternate_name)<<(copy_u8pin_id*4));
            	    	    state_error =ES_OK;
            	      }
            	      else{
            	    	   copy_u8pin_id=copy_u8pin_id-8;
            	           GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_AFRH]&=~(((u32)15)<<(copy_u8pin_id*4));
            	           GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_AFRH]|=(((u32)copy_u8alternate_name)<<(copy_u8pin_id*4));
            	           state_error =ES_OK;
            	      }
            	   }

               }

          }
          else{
        	   state_error =ES_OUT_OF_RANGE;
          }

	  return state_error;
}

/* this function take output value*/
ES_t MGPIO_enumset_pin_value(u16 copy_u8port_name,u8 copy_u8pin_id,u8 copy_u8pin_value){
	   ES_t state_error =ES_NOK;
 	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)&&(copy_u8pin_value<=GPIO_HIGH))
	      {
	    	  if(copy_u8port_name==GPIOH){

	    		  GPIO->GPIO_registers[copy_u8port_name+GPIO_ODR]&=~(((u32)1)<<(copy_u8pin_id));
	    		  GPIO->GPIO_registers[copy_u8port_name+GPIO_ODR]|=(((u32)copy_u8pin_value)<<(copy_u8pin_id));
	    	  }
	    	  else{

	    		  GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_ODR]&=~(((u32)1)<<(copy_u8pin_id));
	    		  GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_ODR]|=(((u32)copy_u8pin_value)<<(copy_u8pin_id));
	    	  }

	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}

/*this function take pointer to char to get on input value of the pin*/
ES_t MGPIO_enumget_pin_value(u16 copy_u8port_name,u8 copy_u8pin_id,u8* copy_u8pin_value){
	   ES_t state_error =ES_NOK;
	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)){
    		  if(copy_u8pin_value==Null){
                 return ES_NULL_POINTER;
    		  }
	    	  if(copy_u8port_name==GPIOH){
	    		  * copy_u8pin_value= read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_IDR]),copy_u8pin_id);

	    	  }
	    	  else{

	    		  * copy_u8pin_value= read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_IDR]),copy_u8pin_id);
	    	  }

	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}
/* this function to lock pin configuration*/
ES_t MGPIO_enumlocked_pin_configuration(u16 copy_u8port_name,u8 copy_u8pin_id){
	   ES_t state_error =ES_NOK;
	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15))
	      {

	    	  if(copy_u8port_name==GPIOH){
	    		  if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK)){
                           return ES_GPIO_LOCKED_PORT;
	    		  }
	    		  else{
	    			       set_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),copy_u8pin_id);
	    		  }
	    	  }
	    	  else{
	    		  if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK)){
	    			       return ES_GPIO_LOCKED_PORT;
	    	      }
	    		  else{
	    			  set_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),copy_u8pin_id);
	    		  }
	    	  }
	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}
/* this function to release lock of pin configuration*/
ES_t MGPIO_enumrelease_pin_configuration(u16 copy_u8port_name,u8 copy_u8pin_id){
	   ES_t state_error =ES_NOK;
	      if(((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH))&&(copy_u8pin_id<=GPIO_PIN_15)){

               if(copy_u8port_name==GPIOH){
	    	           if(read_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK)){
	    	                    return ES_GPIO_LOCKED_PORT;
	    	           }
	    	           else{
	    	  	                clear_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),copy_u8pin_id);
	    	           }
	    	  }
	    	  else{
	    	          if(read_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK)){
	    	  	               return ES_GPIO_LOCKED_PORT;
	    	          }
	    	          else{
	    	  	              clear_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),copy_u8pin_id);
	    	          }
	    	 }
	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}
/* this function to lock GPIO_PORT configuration*/
ES_t MGPIO_enumlocked_port_configuration(u16 copy_u8port_name){
	   ES_t state_error =ES_NOK;
	      if((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH)){
	    	  if(copy_u8port_name==GPIOH){
	    	  	     set_bit((GPIO->GPIO_registers[copy_u8port_name+GPIO_LCKR]),LCKK);
	    	  }
	    	  else{
	    		  set_bit((GPIO->GPIO_registers[(copy_u8port_name*256)+GPIO_LCKR]),LCKK);
	    	  }
	      }
	      else{
	    	  state_error =ES_OUT_OF_RANGE;
	      }
	  return state_error;
}

/* this function to release lock of GPIO_PORT configuration */
ES_t MGPIO_enumrelease_port_configuration(u16 copy_u8port_name){
	 ES_t state_error =ES_NOK;
	 if((copy_u8port_name<=GPIOE)||(copy_u8port_name==GPIOH)){
          if(copy_u8port_name==GPIOH){
        	  set_bit(RCC_AHB1RSTR,7);
          }
          else{
        	  set_bit(RCC_AHB1RSTR,copy_u8port_name);
          }
	 }
	 else{
		 state_error =ES_OUT_OF_RANGE;
	 }

	 return state_error;
}
