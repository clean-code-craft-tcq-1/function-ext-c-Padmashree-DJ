
#include "BMS_BatteryCheck.h"

/**
 ***************************************************************************************************
 * Function Name: HandleBatteryDataOn_Lowerlimit
 * 
 * Function Description: Checks the BAttery Data is approaching lower limit
 *
 * \param  BatteryData_t BatteryData
 *         float Particular
 *                 
 * \return  void
 * \retval  None
 ***************************************************************************************************
 */

void HandleBatteryDataOn_Lowerlimit(BatteryData_t BatteryData, float Particular)
{
    int isBatteryParamstable = BATTERY_HEALTH_OK;
    if (Particular<BatteryData.BatteryDataLowerWarningLimit && Particular>BatteryData.BatteryDataLowerLimit )
    {
        isBatteryParamstable= BATTERY_LOW_WARNING;
    }
    else
    {
        isBatteryParamstable= BATTERY_LOW;
    }
    PrintBatteryHealthStatus(BatteryData,isBatteryParamstable );
}

/**
 ***************************************************************************************************
 * Function Name: HandleBatteryDataOn_Upperlimit
 * 
 * Function Description: Checks the Battery Data is approaching upper limit
 *
 * \param  BatteryData_t BatteryData
 *         float Particular
 *                 
 * \return  void
 * \retval  None
 ***************************************************************************************************
 */
void HandleBatteryDataOn_Upperlimit(BatteryData_t BatteryData, float Particular)
{
    int isBatteryParamstable = BATTERY_HEALTH_OK;
    if (Particular>BatteryData.BatteryDataUpperWarningLimit && Particular<BatteryData.BatteryDataUpperLimit )
    {
        isBatteryParamstable= BATTERY_HIGH_WARNING;
    }
    else
    {
        isBatteryParamstable= BATTERY_HIGH;
    }
    PrintBatteryHealthStatus(BatteryData,isBatteryParamstable );
}