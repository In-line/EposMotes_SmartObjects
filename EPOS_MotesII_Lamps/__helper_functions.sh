#!/bin/sh


# Read the general tools system manual file.
installManual=$(cat "__install_manual.txt")

# The time flag file path
updateFlagFilePath="/home/$USER/epos_flag_file.txt"

# Save the current seconds
if ! [ -f $updateFlagFilePath ]
then
    # Allow this variable to be visible form multiples shell script executions.
    export scriptStartSecond=$(date +%s)
    
    # Create a flag file to avoid override the initial time.
    echo "The EPOS 1.1 time flag" > $updateFlagFilePath
fi


# Calculates and prints to the screen the seconds elapsed since this script started.
showTheElapsedSeconds()
{
    scripExecutionTimeResult=$(($(date +%s)-scriptStartSecond))
    printf "Took '$scripExecutionTimeResult' seconds to run this script.\n"
    
    cleanUpdateFlagFile
}


# Clean the flag file
cleanUpdateFlagFile()
{
    if [ -f $updateFlagFilePath ]
    then
        rm $updateFlagFilePath
    fi
}


# Determine whether its first parameter is empty or not.
#
# Returns 1 if empty, otherwise returns 0.
isEmpty()
{
    if [ -z ${1+x} ]
    then
        return 1
    fi
    
    return 0
}


# Determine whether the first parameter is an integer or not.
#
# Returns 1 if the specified string is an integer, otherwise returns 0.
isInteger()
{
    # Calculates whether the first function parameter $1 is a number
    isEmpty $1
    
    # Captures the return value of the previous function call command
    isEmptyReturnValue=$?
    
    # Notify an invalid USB port number passed as parameter.
    if ! [ $isEmptyReturnValue -eq 1 ]
    then
        if [ "$1" -eq "$1" ] 2>/dev/null
        then
            return 1
        fi
    fi
    
    return 0
}


# Print help to the output stream.
printHelp()
{
    printf "$installManual\n"
    showTheElapsedSeconds
}


# contains(string, substring)
#
# Returns 0 if the specified string contains the specified substring,
# otherwise returns 1.
contains()
{
    string="$1"
    substring="$2"
    
    if test "${string#*$substring}" != "$string"
    then
        return 0    # $substring is in $string
    else
        return 1    # $substring is not in $string
    fi
}


#printf "\nMOTHERFUCKER\n"


