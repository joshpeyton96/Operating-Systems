#C14348526 - Joshua Peyton – Computer Science Infrastructure 
#Assignment7
#Operating Systems

#This script will display a list of options for the user. The user will enter an option number 1-11.
#When an option is entered, the commands in that option will execute and display on screen
#The user will then be promted with the main menu again and asked to enter another option
#The menu will keep on displaying until the user enters the exit option
#If an invalid option is entered then an error message will display

#while and do loop used to loop menu every time user enters option
while true
do
#PS3 is assigned to change the default prompt for when user is prompted to enter an option
PS3='Please enter your choice: ' 
#The options for the main menu will be stored in the option list
options=("Option a - Display Username, Date and Time" "Option b - Edit a file" "Option c - Show current shell, home directory and operating system type" "Option d - Show your current path setting and current working directory" "Option e - Show number of users currently logged" "Option f - Show the OS version, release number and kernal version" "Option g - Show CPU information, processor model name and speed and uptime" "Option h - Display all the directories in PATH in an easy-to-read way ie.                  One line per directory" "Option i - Display information from ls-l command in a more user friendly way" "Option j - Display a summary of the disk space usage for each directory                    argument in terms of bytes, kilobytes and megabytes" "Option k - Exit")
#This is a menu separator used to make the output more user friendly and readable
echo '--------------------------------------------------------------------------------'
echo '                                  Menu                                          '
echo '--------------------------------------------------------------------------------'
#select option in options
select opt in "${options[@]}"
#Cases are used to execute each option displayed on the menu
#The user will be prompted with a list of options in which they will select one by entering 1-11
#The user will enter a option between options 1-11 and the case with the selected option will execute
#An Error message will display if the user enters an invalid option
#The do loop will allow user to enter another option after entering one(Loops back around)
do
    case $opt in 
        #If 1 is entered by user then the below option will execute
        #This option will contain the commands to display the Username, Date and Time
        "Option a - Display Username, Date and Time")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option a                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Current username:"
            id
            echo "Current Date:"
            date
            echo "Current Time:"
            #Current Time is displayed by adding '+%T' to the date command
            date +"%T"
            break
            ;;
        #If 2 is entered by user then the below option will execute
        #This option will allow the user to edit a file using the vi editor
        "Option b - Edit a file")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option b                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Edit a file:"
            #vi will allow the user to enter the vi editor
            vi
            break
            ;;
        #If 3 is entered by user then the below option will execute
        #This option contains the commands to display the current shell, home directory and operating system type
        "Option c - Show current shell, home directory and operating system type")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option c                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Current Shell:"
            echo $SHELL
            echo "Home Directory:"
            echo $HOME
            echo "Operating System Type"
            #The uname command is used to print information about the current system 
            #The -a added to this command makes the command print the operating system type
            uname -a
            break
            ;;
        #If 4 is entered by user then the below option will execute
        #This option contains the commands to display the current path setting and current working directory
        "Option d - Show your current path setting and current working directory")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option d                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Current Path Setting"
            #echo $PATH is simply used to print the current path setting 
            echo $PATH
            echo "Current Working Directory:"
            #pwd command is used to print the name of the current working directory
            pwd  
            break                
            ;;
        #If 5 is entered by user then the below option will execute
        #This option contains the command to display who is currently logged on
        "Option e - Show number of users currently logged")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option e                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Number of users logged on:"
            #The who command prints who is currently logged onto the system
            #The -q displays a count of all the logged in users and displays all login names
            who -q
            break
            ;;
        #If 6 is entered by user then the below option will execute
        #This option contains the commands to dispay the OS version, release number and kernal version
        "Option f - Show the OS version, release number and kernal version")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option f                                        '
            echo '--------------------------------------------------------------------------------'
            echo "The OS version:"
            #The uname command is used to print information about the current system 
            #The -a is added to print the OS Version
            uname -a
            #The uname command is used to print information about the current system 
            #The -r is added to print the release numer
            echo "Release number"
            uname -r
            #The uname command is used to print information about the current system 
            #The -k is added to print the Kernal version
            echo "Kernal version:"
            uname -v
            break
            ;;
        #If 7 is entered by user then the below option will execute
        #This option contains the commands to display the CPU information, processor model name and speed and uptime
        "Option g - Show CPU information, processor model name and speed and uptime")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option g                                        '
            echo '--------------------------------------------------------------------------------'
            echo "CPU information:"
            #The /proc/cpuinfo file contains details about the individual cpu cores
            #The more command displays the text, one screen at a time 
            more /proc/cpuinfo
            echo "Processor model:"
            #The /proc/cpuinfo file contains details about the individual cpu cores
            #The | grep 'model name' | uniq is added to print the processor model
            cat /proc/cpuinfo | grep 'model name' | uniq
            echo "Speed and Uptime"
            #The /proc/cpuinfo file contains details about the individual cpu cores
            #The | grep -i mhz | uniq is added to print the speed
            #The /proc/uptime command simply prints the uptime
            cat /proc/cpuinfo | grep -i mhz | uniq
            cat /proc/uptime
            break 
            ;;
        #If 8 is entered by user then the below option will execute
        #This option contains the commands to display all the direstories in PATH in an easy-to-read way
        "Option h - Display all the directories in PATH in an easy-to-read way ie. One line per directory")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option h                                        '
            echo '--------------------------------------------------------------------------------'
            echo "All the directories in PATH in an easy-to-read way"
            #Command used to display the directories in PATH one line per directory
            echo "${PATH//:/$'\n'}"
            break
            ;;
        #If 9 is entered by user then the below option will execute
        #This option contains the command to display the information from ls-l in a more user frendly way
        "Option i - Display information from ls-l command in a more user friendly way")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option i                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Information from ls-l command in a more user friendly way"
            #The ls command is used to list directory contents
            #The -lh added to the command prints the information is a human-readable and long lasting format
            ls -lh
            break
            ;;
        #If 10 is entered by user then the below option will execute
        #This option contains the command to display a summary of the disk space usage for each firectory argument
        "Option j - Display a summary of the disk space usage for each directory argument in terms of bytes, kilobytes and megabytes")
            #This is an option separator used to make output more user friendly and readable
            echo '--------------------------------------------------------------------------------'
            echo '                                Option j                                        '
            echo '--------------------------------------------------------------------------------'
            echo "Summary of the disk space usage for each directory argument in terms of bytes, kilobytes or megabytes"
            #The df command displays information about the space on the system in bytes, kilobytes and megabytes
            #The -h displays the information in a more human readable format
            df -h
            break
            ;;
        #If 11 is entered by user then the below option will execute
        #This option will simply end the program by using 'break
        "Option k - Exit")
            echo "Exit"
            #exit command will completely exit the shell script
            exit
            ;;
        #Used for Error-checking if an invald option is entered
        *) echo invalid option;;
    esac
done
done
