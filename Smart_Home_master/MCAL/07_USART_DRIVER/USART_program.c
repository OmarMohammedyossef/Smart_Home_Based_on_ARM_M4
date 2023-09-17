/*
  =============================================================================
 * Name		:USART_program.c
 * Author		:Omar Elshamy
 * Version        : _1_	
 * Created on	:5/9/2023
 ==============================================================================
 */
#include "../../LIB/STD_datatypes.h"
#include "USART_configuration.h"
#include "USART_private.h"
#include "USART_interface.h"

void(*ptr1)(void)=0;
void(*ptr2)(void)=0;

u8 flag=1;
s8 i=0;
u8* ar[10]={0};

void USART_vInit(void){

   // USART_BRR= (u8)((f32)frequency/(f32)(16*baud_rate));

	set_bit(USART_CR1,UE);
	//set_bit(USART_CR1,PSC0);
	//set_bit(USART_CR1,HDSEL);
/* select type of parity */
#if    parity_type == no_parity
	   clear_bit(USART_CR1,PCE);

#elif  parity_type == even_parity
	   clear_bit(USART_CR1,PS);

#else
	   set_bit(USART_CR1,PS);

#endif

/* select number of stop bits */
	assign_xbits_value(USART_CR2,3,number_of_stop_bits,STOP0);

/* select number of data bits in frame */
#if     number_of_data_bits == eight_data_bits
	      clear_bit(USART_CR1,DATA);
#else
	      set_bit(USART_CR1,DATA);

#endif
	// assign baud rate
	      clear_bit(USART_CR1,OVER);
 f32 bud_rate = ((f32)frequency/(f32)(16*baud_rate));
 u32 bud_rateint = (u32)bud_rate;
          assign_xbits_value(USART_BRR,0xFFF,bud_rateint,4);
	      assign_xbits_value(USART_BRR,15,((bud_rate-bud_rateint)*16),0);


/* enable or disable interrupts */
#if    TXC_interrupt == disable
	    clear_bit(USART_CR1,TXEIE);
#else
	    set_bit(USART_CR1,TXEIE);
#endif

#if    RXC_interrupt == disable
	    clear_bit(USART_CR1,RXNEIE);
#else
	    set_bit(USART_CR1,RXNEIE);
#endif

#if    TC_interrupt == disable
	    clear_bit(USART_CR1,TCIE);
#else
	    set_bit(USART_CR1,TCIE);
#endif

	    /* select job of USART */
#if     USART_job == reciever
	    set_bit(USART_CR1,RE);
#elif   USART_job == transmitter
	    set_bit(USART_CR1,TE);
#else
	    set_bit(USART_CR1,RE);
	    set_bit(USART_CR1,TE);
#endif

}
void USART_vTransmit(u8 data){
   while(!read_bit(USART_SR,TC));
   USART_DR = (u32)data;
  // assign_xbits_value(USART_DR,0x1FF,data,0);
}
void USART_vTransmit_noblock(u8 data){
	USART_DR = (u32)data;
}
u8 USART_u8Recieve(u8* data){
	while(!read_bit(USART_SR,RXNE));
	//if(!read_bit(USART_SR,ORE)&&!read_bit(USART_SR,FE)&&!read_bit(USART_SR,PE)){
	   *data = USART_DR;
	  // return 1;
	//}
	return 1;
}
u8 usart_voidrecieve_noblock(void){
	return (u8)USART_DR;
}
u16 usart_u16get_frame(u16 data){
	if(parity_type==no_parity){
		data=data<<1;
		data=data|(1<<(number_of_data_bits+1));
		if(number_of_stop_bits==two_stop_bit){
			data=data|(1<<(number_of_data_bits+2));
		}
		return data;
	}
	else{
		if(parity_type==even_parity){
			u8 i,count=0;
			for(i=0;i<number_of_data_bits;i++){
				if((data>>i)&1){
					count++;
				}
			}
			data=data<<1;
			if(count%2){
				data=data&(~(1<<(number_of_data_bits+1)));
				data=data|(1<<(number_of_data_bits+2));
				if(number_of_stop_bits==two_stop_bit){
					data=data|(1<<(number_of_data_bits+3));
				}
			}
			else{
				data=data|(1<<(number_of_data_bits+1));
				data=data|(1<<(number_of_data_bits+2));
				if(number_of_stop_bits==two_stop_bit){
					data=data|(1<<(number_of_data_bits+3));
				}
			}
			return data;
		}
		else{
			u8 i,count=0;
			for(i=0;i<number_of_data_bits;i++){
				if((data>>i)&1){
					count++;
				}
			}
			data=data<<1;
			if(count%2){
				data=data|(1<<(number_of_data_bits+1));
				data=data|(1<<(number_of_data_bits+2));
				if(number_of_stop_bits==two_stop_bit){
					data=data|(1<<(number_of_data_bits+3));
				}
			}
			else{
				data=data&(~(1<<(number_of_data_bits+1)));
			    data=data|(1<<(number_of_data_bits+2));
				if(number_of_stop_bits==two_stop_bit){
					data=data|(1<<(number_of_data_bits+3));
				}
			}
			return data;
		}
	}
}
void USART_vTransmit_string(u8* data){
	u8 i=0;
	for(;data[i];i++){
		USART_vTransmit(data[i]);
	}
	USART_vTransmit('#');
}
u8 USART_u8Recieve_string(u8* data){
	u8 check=0;
	check=USART_u8Recieve(data);
  if(check!=0){
	 for(;(*data)!='#';){
		 ++data;
		/* if((*data) != 1){
			 --data;
			 break;
		 }*/
		 check=USART_u8Recieve(data);
		 if(check==0)break;
   	}
  }
	*data = 0;
	return 1;
}
void USART_vTransmit_number(u32 data){
	/*USART_vTransmit(((u8)data));
	USART_vTransmit(((u8)(data>>8)));
	USART_vTransmit(((u8)(data>>16)));
	USART_vTransmit(((u8)(data>>24)));*/
	u8* ptr=&data;
	USART_vTransmit(ptr[0]);
	USART_vTransmit(ptr[1]);
	USART_vTransmit(ptr[2]);
	USART_vTransmit(ptr[3]);
}
u8 USART_u8Recieve_number(u32* data){
	u8* pt=data;
	u8 check=0,i=0;
	for(;i<4;i++){
	check=USART_u8Recieve((pt+i));
	if(!check)break;
	}
	return check;
}
void uart_voidtransmit_checksum(u8* data){
	u8 i=0,j=0;
	u16 sum=0;
	for(;data[i];i++);
	USART_vTransmit(i);
	for(;data[j];j++){
		USART_vTransmit(data[j]);
		sum+=data[j];
	}
	USART_vTransmit((u8)sum);
	USART_vTransmit((u8)(sum>>8));
}
u8 uart_u8recieve_checksum(u8* data){
	u8 length=0,i=0;
	u16 sum=0,sum1=0;
	u8* pt=&sum;
	USART_u8Recieve(&length);
	for(;i<length;i++){
		USART_u8Recieve((data+i));
		sum1+=data[i];
	}
	data[length]=0;
	USART_u8Recieve(pt);
	USART_u8Recieve((pt+1));
	if(sum==sum1){
		return 1;
	}
	return 0;
}

/* callback function for transmit complete */
void uart_voidcallbacktransmit(void(*ptr)(void)){
	if(ptr!=Null) ptr1=ptr;
}

/* callback function for receive complete */
void uart_voidcallbackrecieve(void(*ptr)(void)){
	if(ptr!=Null) ptr2=ptr;
}

u8* uart_voidtransmitstringASC(u8* data){
   if(i<=9){
      ar[i]=data;
      i++;
     if(flag==1){
    	 flag=0;
	    USART_vTransmit_noblock(ar[0][0]);

      }
     return "OK" ;
   }
   else{
    return "array is full" ;
   }
}
u8* uart_voidrecievestringASC(void){
	//u8* message="array is empty";
     i--;
     if(i!=-1){
    	 return ar[i];
     }
     else{
    	 i=0;
     return "array is empty" ;
     }
}
/* ISR for USART1 */
void USART1_IRQHandler(void){
	if(read_bit(USART_SR,TC)){
	   if(ptr1 != Null){
		  ptr1();
	   }
	   else{
		   //do nothing
	   }
	}
	if(read_bit(USART_SR,RXNE)){
	   if(ptr2 != Null){
		  ptr2();
	   }
	   else{
		   //do nothing
	   }
	}
}




