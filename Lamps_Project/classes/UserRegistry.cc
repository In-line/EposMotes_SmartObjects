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
 * Preprocessor directive designed to cause the current source file to be included only once in a
 * single compilation. Thus, serves the same purpose as #include guards, but with several
 * advantages, including: less code, avoidance of name clashes, and sometimes improvement in
 * compilation speed. In main file this is enabled by default.
 */
#pragma once


/**
 * #define __SYS_NS	   System
 * #define __USING_SYS using namespace __SYS_NS
 */
__USING_SYS;



/**
 * This class groups together the user id and the its priority used to help decides which user wins
 * the lamp configuration control.
 */
class UserRegistry
{
public:
    
    /**
     * To creates a new lampBoard object and sets this board ID and priority.
     * 
     * @param boardId                 @see UserRegistry::userBoardId member class variable declaration/doc.
     * @param priority                @see UserRegistry::userBoardPriority member class variable declaration/doc.
     */
    UserRegistry( const int identification, const int priority ) :
                  userBoardId( identification ),
                  userBoardPriority( priority )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE UserRegistry::UserRegistry(2) CONSTRUCTOR! | "
                << "identification: " << identification << " priority: " << priority );
    }
    
    /**
     * Gets the current user identification number.
     * 
     * @return the current user identification number as an integer number.
     */
    const int getUserID()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE UserRegistry::getUserID(0)" );
        return 0; // Just like a Guto's EPOS implementation.
    }
    
    /**
     * Gets the current user priority.
     * 
     * @return the current user priority as an integer number.
     */
    const int getUserPriority()
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE UserRegistry::getUserPriority(0)" );
        return 0; // Just like a Guto's EPOS implementation.
    }
    
    
private:
    
    /**
     * An unique integer representing the user board identification number as an integer number.
     */
    const int userBoardId;
    
    /**
     * The current user board priority as an integer number.
     */
    const int userBoardPriority;
    
    /**
     * Disables the default constructor.
     */
    UserRegistry() :
            userBoardId( 0 ),
            userBoardPriority( 0 )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE UserRegistry::UserRegistry(0) THE DISABLED CONSTRUCTOR!" );
    }
    
    // private magic stuff
    
    
    
};








