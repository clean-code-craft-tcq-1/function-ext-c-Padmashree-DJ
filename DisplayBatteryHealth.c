#include <stdio.h>
#include "BMS_BatteryCheck.h"


const char *BatteryHealthMessage[] =
{
    "is Unstable! Take Action Immediately!!!",
    "is Stable",
    "is lower than the minimum value permissible",
    "is higher than the maximum value permissible",
    "is approaching lower limit.",
    "is approaching higher limit."
};

const char *BatteryHealthMessageGerman[] =
{
    "ist Unstable! Sofort handeln!!!",
    "ist stabil",
    "niedriger als der zulässige Mindestwert ist",
    "höher als der zulässige Höchstwert ist",
    "nähert sich der unteren Grenze.",
    "nähert sich einer höheren Grenze."
};

/**
***************************************************************************************************
* Function Name: PrintBatteryHealthStatus
* 
* Function Description: Displays the BMS battery status message.
*
* \param  BatteryData_t BatteryData
*         int IndexOfBatteryHealthMessage
*         
* \return  void
* \retval  None
***************************************************************************************************
*/
void PrintBatteryHealthStatus(BatteryData_t BatteryData, int IndexOfBatteryHealthMessage)
{
    int Input_Language=0;
    printf("Please input the language you want to continue reading with \n");
    printf("Press 1 for English \n");
    printf("Press 2 for German \n");
    scanf(" %d ", &Input_Language );
    if (Input_Language==1) 
	{
      printf("%s %s \n", BatteryData.BatteryParticular, BatteryHealthMessage[IndexOfBatteryHealthMessage]);
	}
    else if (Input_Language==2) 
	{
      printf("%s %s \n", BatteryData.BatteryParticular, BatteryHealthMessageGerman[IndexOfBatteryHealthMessage]);
	}
    else
    {
        
    }
}
