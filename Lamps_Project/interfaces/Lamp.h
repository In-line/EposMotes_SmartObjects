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


#include <headers/lamps_project_debugger.h>
#include <headers/array_operations.h>


/**
 * DO NOT MODIFIY IT!
 * 
 * @see The Class LampBoard main include declaration/explanation.
 */
#include <classes/CommunicationSubject.cc>



/**
 * This class is the abstract class to the Lamp's objects.
 */
class Lamp
{
public:
    
    /**
     * Adds a new lamp into the controlling system.
     * 
     * @param setting        an LampConfiguration configuration object.
     */
    virtual void setNewUserSetting( LampConfiguration* ) = 0;
    
    /**
     * Reads the lamp configuration and get it current desired bright.
     * 
     * @return an int as the current lamp bright.
     */
    virtual int getCurrentBright() = 0;
    
    
protected:
    
    /**
     * Contains this lamp configuration.
     */
    LampConfiguration* configuration;
    
    /**
     * Contains this lamp configuration.
     */
    char* lampColor;
    
};







