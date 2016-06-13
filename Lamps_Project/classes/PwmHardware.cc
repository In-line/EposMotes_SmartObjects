/**
* This work is licensed under the EPOS Software License v1.0.
* A copy of this license is available at the EPOS system source tree root.
* Note that EPOS Software License applies to both source code and executables.
*
*  You should have received a copy of the EPOS Software License v1.0 along
*  with this program. If not, see
*  <http://epos.lisha.ufsc.br/EPOS+Software+License+v1.0>.
*
******************************************************************************
*/


/**
 * DO NOT MODIFIY IT!
 * 
 * @see The Class LampBoard main include declaration/explanation.
 */
#include <interfaces/LampControlStrategy.h>



void PWMInterrupt()
{
    static int powerToApply [MAX_LEDS_ALLOWED_TO_BE_USED];
    
    static int          leds[]       = { 10, 9, 11, 23, 8 };
    static int          dummyCounter = 0;
    static unsigned int checkSensor  = 0;
    
    if( !checkSensor )
    {
    	for( unsigned int currentIndex = 0; currentIndex < MAX_LEDS_ALLOWED_TO_BE_USED; ++currentIndex )
    	{
    		powerToApply[ currentIndex ] = Alternative2( power[ currentIndex ] );
    	}
    }
    
    // not all leds are actually used. Only the RGB ones (the first 3)
    
    for( unsigned int currentIndex = 0; currentIndex < MAX_LEDS_ALLOWED_TO_BE_USED; ++currentIndex )
    {
        if( dummyCounter < powerToApply[ currentIndex ] )
        {
            turn_led( leds[ currentIndex ], true );
        }
        else
        {
            turn_led( leds[ currentIndex ], false );
        }
    }
    
    //Check sensor every 3 frames.
    checkSensor = ( checkSensor + 1 ) % 300;
    dummyCounter = ( dummyCounter + 1 ) % 100;
}



/**
 * This class is the interface to an strategy to control the Lamp's objects.
 */
class PwmHardware : public LampControlStrategy
{
public:
    
    /**
     * Gets the only allowed PwmHardware's instance by lazy initialization.
     * 
     * @return the unique existent PwmHardware's instance.
     */
    static PwmHardware& getInstance()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE PwmHardware::getInstance(0)" );
        
        static PwmHardware instance;
        return instance;
    }
    
    /**
     * @see LampControlStrategy::addNewLamp( Lamp, LampConfiguration ) member abstract class declaration.
     */
    void addNewLamp( Lamp* lamp, LampConfiguration* setting )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE PwmHardware::addNewLamp(2)" );
    }
    
    /**
     * @see LampControlStrategy::setNewUserSettings( Lamp, LampConfiguration ) member abstract class declaration.
     */
    void setNewUserSettings( Lamp* lamp, LampConfiguration* newSetting )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE PwmHardware::setNewUserSettings(2)" );
    }
    
    
private:
    
    /**
     * Creates an PwmHardware object ready to be used by the singleton design pattern.
     */
    PwmHardware()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE PwmHardware::PwmHardware(0) THE PRIVATE CONSTRUCTOR!" );
        
        // To creates a interrupt by stealing one Operation System Interrupt. This theft has know side
        // affects until now, but it could be causing the 'traits.h' debug level info, to crash this
        // program while running. The the file at 'file/trace_debug_info_error.txt' on this project
        // for more information about it.
        // The values tested as the interruption time to cause the LEDs to show a human visual blink
        // when the LEDs power are set to lower values as 1, instead of 100 are 250. Note that not all
        // colors showed blinking when using higher values. Some color as Red and Green, just presented
        // themselves with lower bight then they should when the their minimum power is set.
        // When it is set to 100, there are any blink perception.
        DEBUGGERLN( 4, "RUNNING: TSC_Timer pwmTimer( 100, &PWMInterrupt )" );
        TSC_Timer pwmTimer( 100, &PWMInterrupt );
    }
    
    /**
     * Do not implement it. Disable the copy constructor to avoid multiple singleton object copies.
     */
    PwmHardware( PwmHardware const& );
    
    /**
     * Do not implement it. Disable the assignment operator to avoid multiple singleton object copies.
     */
    void operator=( PwmHardware const& );
    
    // PwmHardware magic private methods
    
    
    
};







