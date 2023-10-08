/*
 * GPIO_interface.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

#include "MGPIO_private.h"


/*struct to conf pin with info */
#define NUMBER_OF_USED_PINS 	3

typedef struct
{
	u8 PORT_ID     ;
	u8 PIN_ID      ;
	u8 MODE        ;
//	u8 OTYPE       ;
//	u8 OSPEED      ;

}Dio_ChannelGroupType, pinInfo;
pinInfo arrOfPins[NUMBER_OF_USED_PINS];

void GPIO_VidInit();
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level);
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
/*
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );
*/
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);

Dio_ChannelGroupType ArrOfGroup[NUMBER_OF_USED_PINS_GROUP];

#endif /* MGPIO_INTERFACE_H_ */
