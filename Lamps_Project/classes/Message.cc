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
 * This the message send by the boards to communicate with each other.
 */
struct Message
{
public:
    
    /**
     * This is the text message to be send.
     */
    const char* message;
    
    /**
     * This is the configuration object sent by the UserBoard, and to be received by the LampBoard.
     */
    LampConfiguration* config;
    
    /**
     * Creates a new message to be sent by the radio.
     * 
     * @param lampType          see Message::message public constant class atribute.
     * @param specialFlags      see Message::config public constant class atribute.
     */
    Message( const char* message, LampConfiguration* config ) :
            message( message ),
            config( config )
    {
        DEBUGGERLN( 2, "I AM ENTERING ON THE Message::Message(0) CONSTRUCTOR! Message: " << message );
        
        // TODO: To find out why calling this here, crashes/breaks the program execution.
        // DEBUGGERLN( 2, ", Bright: ", config->getBright() );
    }
    
};











