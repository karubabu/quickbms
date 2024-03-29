int verbose_options(u8 *arg) {
    u8      *p;

    if(!arg || (strlen(arg) < 2)) return -1;
    if(((arg[0] != '-') && (arg[0] != '/')) || (strlen(arg) != 2)) {
        for(p = arg; (*p == '-') || (*p == '/'); p++);
             if(!stricmp(p, "help"))        strcpy(arg, "-h");
        else if(!stricmp(p, "commands"))    strcpy(arg, "-c");
        else if(!stricmp(p, "filter"))      strcpy(arg, "-f");
        else if(!stricmp(p, "list"))        strcpy(arg, "-l");
        else if(!stricmp(p, "verbose"))     strcpy(arg, "-v");
        else if(!stricmp(p, "debug"))       strcpy(arg, "-V");
        else if(!stricmp(p, "listfile"))    strcpy(arg, "-L");
        else if(!stricmp(p, "hex"))         strcpy(arg, "-x");
        else if(!stricmp(p, "write"))       strcpy(arg, "-w");
        else if(!stricmp(p, "endian"))      strcpy(arg, "-E");
        else if(!stricmp(p, "void"))        strcpy(arg, "-0");
        else if(!stricmp(p, "reimport"))    strcpy(arg, "-r");
        else if(!stricmp(p, "reinject"))    strcpy(arg, "-r");
        else if(!stricmp(p, "sockets"))     strcpy(arg, "-n");
        else if(!stricmp(p, "network"))     strcpy(arg, "-n");
        else if(!stricmp(p, "process"))     strcpy(arg, "-p");
        else if(!stricmp(p, "audio"))       strcpy(arg, "-A");
        else if(!stricmp(p, "video"))       strcpy(arg, "-g");
        else if(!stricmp(p, "winmsg"))      strcpy(arg, "-m");
        else if(!stricmp(p, "calldll"))     strcpy(arg, "-C");
        else if(!stricmp(p, "hex_html"))    strcpy(arg, "-H");
        else if(!stricmp(p, "hex_console")) strcpy(arg, "-X");
        else if(!stricmp(p, "update"))      strcpy(arg, "-u");
        else if(!stricmp(p, "continue"))    strcpy(arg, "-.");
        else if(!stricmp(p, "continue_anyway"))     strcpy(arg, "-.");
        else if(!stricmp(p, "XDBG_ALLOC_ACTIVE"))   strcpy(arg, "-9");
        else if(!stricmp(p, "XDBG_ALLOC_INDEX"))    strcpy(arg, "-8");
        else if(!stricmp(p, "XDBG_ALLOC_VERBOSE"))  strcpy(arg, "-7");
        else if(!stricmp(p, "XDBG_HEAPVALIDATE"))   strcpy(arg, "-6");
        else if(!stricmp(p, "gui"))         strcpy(arg, "-G");
        else if(!stricmp(p, "quiet"))       strcpy(arg, "-q");
        else return -1;
    }
    return 0;
}



#define myhelp_option_t     "0:text1, 1:text2, 2:text3, 3:json1, 4:json2, 5:web, 6:dos, 7:ls"



void myhelp(u8 *argv0) {
    printf("\n"
        "Usage: %s\n"
        "         [options]\n"
        "           <script.BMS>\n"
        "             <input_archive/folder>\n"
        "               [output_folder]\n"
        "\n"
        "Options:\n"
        "-l     list the files without extracting them\n"
        "-f W   filter the files to extract using the W wildcards separated by comma or\n"
        "       semicolon, example -f \"*.mp3,*.txt;*myname*\"\n"
        "       if the filter starts with ! it's considered an ignore/exclusion filter,\n"
        "       it can be a text file containing multiple filters too, * and {} are same\n"
        "       example: quickbms -f \"*.mp3;!*.ogg\" script.bms archive.dat output\n"
        "       example: quickbms -f myfilters_list.txt script.bms archive.dat\n"
        "       use {} instead of * to avoid issues on Windows, multiple -f are ok too\n"
        "-F W   as above but works only with the files in the input folder (if used)\n"
        "       example: quickbms -F \"*.dat\" script.bms input_folder output_folder\n"
        "-o     overwrite the output files without confirmation if they already exist\n"
        "-k     keep the current files if already exist without asking (skip all)\n"
        "-K     automatically rename the output files if duplicates already exist\n"
        "-r     experimental reimport option that should work with many archives:\n"
        "         quickbms script.bms archive.pak output_folder\n"
        "         modify the needed files in output_folder and maybe remove the others\n"
        "         quickbms -w -r script.bms archive.pak output_folder\n"
        "       you MUST read section 3 of quickbms.txt before using this feature,\n"
        "       use -r -r for the alternative and better REIMPORT2 mode\n"
        "       use -r -r -r for REIMPORT3 that shrinks/enlarges archive if no offset\n"
        "-u     check if there is a new version of QuickBMS available\n"
        "-i     generate an ISO9660 file instead of extracting every file, the name of\n"
        "       the ISO image will be the name of the input file or folder\n"
        "-z     exactly as above but it creates a ZIP file instead of an ISO image\n"
        "\n"
        "Advanced options:\n"
        "-d     automatically create an additional output folder with the name of the\n"
        "       input folder and file processed, eg. models/mychar/mychar.arc/*,\n"
        "       -d works also if input and output folders are the same (rename folder)\n"
        "-D     like -d but without the folder with the filename, eg. models/mychar/*\n"
        "-E     automatically reverse the endianess of any input file by simply reading\n"
        "       each field and writing the reversed value, each Get produces a Put\n"
        "-c     old quick list of basic BMS commands and some notes about this tool\n"
        "-S CMD execute the command CMD on each file extracted, you must specify the\n"
        "       #INPUT# placeholder which will be replaced by the name of the file\n"
        "       example: -S \"lame.exe -b 192 -t --quiet #INPUT#\"\n"
        "-Y     automatically answer yes to any question\n"
        "-O F   redirect the output of all the extracted files to the output file F\n"
        "-s SF  add a script file or command before the execution of the input script,\n"
        "       useful if an archive uses a different endianess or encryption and so on\n"
        "       SF can be a script or directly the bms instruction you want to execute\n"
        "-.     don't terminate QuickBMS if there is an error while parsing multiple\n"
        "       files (like wrong compression or small file), just continue with the\n"
        "       other files in the folder; useful also in rare cases in reimport mode\n"
        "\n"
        "Debug and experimental options:\n"
        "-v     verbose debug script information, useful for verifying possible errors\n"
        "-V     alternative verbose info, useful for programmers and formats debugging\n"
        "-q     quiet, no *log information\n"
        "-Q     very quiet, no information displayed except the Print command\n"
        "-L F   dump the offset, size and name of the extracted files into the file F\n"
        "-x     use the hexadecimal notation in myitoa (debug)\n"
        "-0     no extraction of files, useful for testing a script without using space\n"
        "-R     needed for programs that act as interface for QuickBMS and in batch\n"
        "-a S   pass arguments to the input script that will take the names\n"
        "       quickbms_arg1, quickbms_arg2, quickbms_arg3 and so on, note they are\n"
        "       handled as arguments so pay attention to spaces and commas, eg:\n"
        "         -a \"arg1 \\\"arg 2\\\", arg3\"\n"
        "         -a arg1 -a \"\\\"arg 2\\\"\" -a arg3\n"
        "       a full backup of the whole -a options is on the var quickbms_arg\n"
        "-H     experimental HTML hex viewer output, use it only with very small files!\n"
        //"       T can be -1, 1, 2 or 3 and is a different type of output\n"
        "-X     experimental hex viewer output on the console (support Less-like keys)\n"
        "-9     toggle XDBG_ALLOC_ACTIVE  (%s)\n"
        "-8     toggle XDBG_ALLOC_INDEX   (%s)\n"
        "-7     toggle XDBG_ALLOC_VERBOSE (%s)\n"
        "-6     toggle XDBG_HEAPVALIDATE  (%s)\n"
        "-3     execute an INT3 before each CallDll, compression and encryption\n"
        "-I     toggle variable names case sensitivity (default %s)\n"
        "-M F   experimental compare and merge feature that allows to compare the\n"
        "       extracted files with those located in the folder F, currently this\n"
        "       experimental option will create files of 0 bytes if they are not\n"
        "       different, so it's not simple to identify what files were written\n"
        "-Z     input file cleaner, in reimport mode replaces all archived files with\n"
        "       zeroes, no matter if they exist or not in the folder, will be all zeroed\n"
        "-P CP  set the codepage to use (default utf8), it can be a number or string\n"
        "-T     do not delete the TEMPORARY_FILE at the end of the process\n"
        "-N     decimal names for files without a name: 0.dat instead of 00000000.dat\n"
        "-e     ignore the compression errors and dump the (wrong) output data anyway\n"
        "-J     all the constant strings are considered Java/C escaped strings (cstring)\n"
        "-B     debug option dumping all the non-parsed content of the open files, the\n"
        "       data will be saved in the output folder as QUICKBMS_DEBUG_FILE*\n"
        "-W P   experimental web API (P is the port) and pipe/mailslot IPC interface\n"
        "-t N   experimental tree-view of the extracted/listed files where N is:\n"
        "       "myhelp_option_t"\n"
        "-U [S] list of available compression algorithms, use S for searching names\n"
        "-#     in reimport mode checks if the archived files and those to reimport are\n"
        "       the same (hash), it's useful if you didn't remove the unmodified files\n"
        "-j     force UTF16 output in some functions, for example with SLog\n"
        "-b C   use C (char or hex) as filler in reimporting if the new file is smaller,\n"
        "       by default it's used space in SLog and 0 for Log and CLog\n"
        "\n"
        "Features and security activation options:\n"
        "-w     enable the write mode required to write physical input files with Put*\n"
        "-C     enable the usage of CallDll without asking permission\n"
        "-n     enable the usage of network sockets\n"
        "-p     enable the usage of processes\n"
        "-A     enable the usage of audio device\n"
        "-g     enable the usage of video graphic device\n"
        "-m     enable the usage of Windows messages\n"
        "-G     force the GUI mode on Windows, it's automatically enabled if you\n"
        "       double-click on the QuickBMS executable\n"
        "\n"
        "No output_folder: use current directory\n"
        "output_folder \"\": use same folder of input file, useful with input directories\n"
        "\n"
        "Examples:\n"
        "  quickbms c:\\zip.bms c:\\myfile.zip \"c:\\new folder\"\n"
        "  quickbms -l -f \"*.txt;*.dds\" zip.bms myfile.zip\n"
        "  quickbms -F \"{}.bff\" c:\\nfsshift.bms c:\\Shift\\Pakfiles c:\\output\n"
        "\n"
        "Check quickbms.txt for the full manual and the list of additional credits.\n"
        "\n", argv0,
        XDBG_ALLOC_ACTIVE  ? "enabled" : "disabled",
        XDBG_ALLOC_INDEX   ? "enabled" : "disabled",
        XDBG_ALLOC_VERBOSE ? "enabled" : "disabled",
        XDBG_HEAPVALIDATE  ? "enabled" : "disabled",
        g_insensitive      ? "insensitive" : "sensitive");
}



void quick_bms_list(void) {
    fputs("\n"
        "quick reference list of the BMS commands:\n"
        "\n"
        " CLog <filename> <offset> <compressed_size> <uncompressed_size> [file]\n"
        "    extract the file at give offset decompressing its content\n"
        "\n"
        " Do\n"
        " ...\n"
        " While <variable> <condition> <variable>\n"
        "    perform a loop which ends when the condition is no longer valid\n"
        "\n"
        " FindLoc <variable> <type> <string> [file] [ret_if_err]\n"
        "    if the string is found put its offset in the variable\n"
        "    by default if FindLoc doesn't find the string it terminates the script\n"
        "    while if ret_if_err is specified (for example -1 or \"\") it will be put in\n"
        "    variable instead of terminating\n"
        "\n"
        " For [variable] = [value] [To] [variable]\n"
        " ...\n"
        " Next [variable]\n"
        "    classical for(;;) loop, Next simply increments the value of the variable\n"
        "    the arguments are optionals for using this For like an endless loop and\n"
        "    To can be substituited with any condition like != == < <= > >= and so on\n"
        "\n"
        " Break\n"
        "    quit a loop (experimental)\n"
        "\n"
        " Get <variable> <type> [file]\n"
        "    read a number (8, 16, 32 bits) or a string\n"
        "\n"
        " GetDString <variable> <length> [file]\n"
        "    read a string of the specified length\n"
        "\n"
        " GoTo <offset> [file]\n"
        "    reach the specified offset, if it's negative it goes from the end\n"
        "\n"
        " IDString [file] <string>\n"
        "    check if the data in the file matches the given string\n"
        "\n"
        " Log <filename> <offset> <size> [file]\n"
        "    extract the file at the given offset with that size\n"
        "\n"
        " Math <variable> <operator> <variable>\n"
        "    perform a mathematical operation on the first variable, available op:\n"
        "    + * / - ^ & | % ! ~ << >> r (rot right) l (rot left) s (bit s) w (byte s)\n"
        "\n"
        " Open <folder> <filename> <file>\n"
        "    open a new file and assign the given file number\n"
        "\n"
        " SavePos <variable> [file]\n"
        "    save the current offset in the variable\n"
        "\n"
        " Set <variable> [type] <variable>\n"
        "    assign the content of the second variable to the first one, type ignored\n"
        "\n"
        " String <variable> <operator> <variable>\n"
        "    perform an append/removing/xor operation on the first variable\n"
        "\n"
        " CleanExit\n"
        "    terminate the extraction\n"
        "\n"
        " If <variable> <criterium> <variable>\n"
        " ...\n"
        " Else / Elif / Else If\n"
        " ...\n"
        " EndIf\n"
        "    classical if(...) { ... } else if { ... } else { ... }\n"
        "\n"
        " GetCT <variable> <type> <character> [file]\n"
        "    read a string (type is useless) delimited by the given character\n"
        "\n"
        " ComType <type> [dictionary]\n"
        "    specify the type of compression to use in CLog: quickbms.txt for the list\n"
        "\n"
        " ReverseLong <variable>\n"
        "    invert the order/endianess of the variable\n"
        "\n"
        " Endian <type>\n"
        "    choose between little and big endian order of the read numbers\n"
        "\n"
        " FileXOR <string_of_numbers> [offset]\n"
        "    xor the read data with the sequence of numbers in the given string\n"
        "\n"
        " FileRot13 <string_of_numbers> [offset]\n"
        "    add/substract the read data with the sequence of numbers in the string\n"
        "\n"
        " Strlen <variable> <variable>\n"
        "    put the length of the second variable in the first one\n"
        "\n"
        " GetVarChr <variable> <variable> <offset> [type]\n"
        "    put the byte at the given offset of the second variable in the first one\n"
        "\n"
        " PutVarChr <variable> <offset> <variable> [type]\n"
        "    put the byte in the second variable in the first one at the given offset\n"
        "\n"
        " Padding <number> [file]\n"
        "    adjust the current offset of the file using the specified number (size of\n"
        "    padding), note that at the moment the padding is performed only when\n"
        "    this command is called and not automatically after each file reading\n"
        "\n"
        " Append\n"
        "    enable/disable the writing of the data at the end of the files with *Log\n"
        "\n"
        " Encryption <algorithm> <key> [ivec] [mode] [keylen]\n"
        "    enable that type of decryption: quickbms.txt for the list\n"
        "\n"
        " Print \"message\"\n"
        "    display a message, you can display the content of the variables simply\n"
        "    specifying their name between '%' like: Print \"my offset is %OFFSET%\"\n"
        "\n"
        " GetArray <variable> <array_num> <index>\n"
        "    get the value stored at the index position of array_num\n"
        "\n"
        " PutArray <array_num> <index> <variable>\n"
        "    store the variable at the index position of array_num\n"
        "\n"
        " StartFunction NAME\n"
        " ...\n"
        " EndFunction\n"
        " CallFunction NAME\n"
        "    experimental functions for recursive archives\n"
        "\n"
        "Refer to quickbms.txt for the rest of the commands and their details!\n"
        "\n"
        "NOTES:\n"
        "- a variable and a fixed number are the same thing internally in the tool\n"
        "  because all the data is handled as strings with the consequent pros\n"
        "  (incredibly versatile) and cons (slowness with some types of scripts)\n"
        "- everything is case insensitive (ABC is like abc) except the content of\n"
        "  strings and variables (excluded some operations like in String)\n"
        "- the [file] field is optional, if not specified it's 0 so the main file\n"
        "- also the final ';' char of the original BMS language is optional\n"
        "- example of <string_of_numbers>: \"0x123 123 456 -12 -0x7f\" or 0xff or \"\"\n"
        "- both hexadecimal (0x) and decimal numbers are supported, negatives included\n"
        "- all the mathematical operations are performed using signed 32 bit numbers\n"
        "- available types of data: long (32 bits), short (16), byte (8), string\n"
        "- all the fixed strings are handled in C syntax like \"\\x12\\x34\\\\hello\\\"bye\\0\"\n"
        "- do not use variable names which start with a number like 123MYVAR or -MYVAR\n"
        "- if you use the file MEMORY_FILE will be used a special memory buffer, create\n"
        "  it with CLog or Log and use it normally like any other file\n"
        "- is possible to use multiple memory files: MEMORY_FILE, MEMORY_FILE2,\n"
        "  MEMORY_FILE3, MEMORY_FILE4 and so on\n"
        "- use TEMPORARY_FILE for creating a file with this exact name also in -l mode\n"
        "\n"
        "information about the original BMS scripting language and original examples:\n"
        "  http://wiki.xentax.com/index.php/BMS\n"
        "  http://multiex.xentax.com/complete_scripts.txt\n"
        "\n"
        "check the source code of this tool for the additional enhancements implemented\n"
        "by me (like support for xor, rot13, lzo, lzss, zlib/deflate and so on) or send\n"
        "me a mail because various features are not documented yet or just watch the\n"
        "examples provided on the project's homepage which cover ALL the enhancements:\n"
        "  http://quickbms.com\n"
        "\n"
        "the tool supports also the \"multiex inifile\" commands in case of need.\n"
        "\n", stdout);
}



void quickbms_comp_print(u8 *name) {
    int     i;
    for(i = 0; quickbms_comp_list[i].name; i++) {
        if(!name || stristr(quickbms_comp_list[i].name, name)) {
            printf("%-4d %s\n", i, quickbms_comp_list[i].name);
        }
    }
}


