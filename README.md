# VersionControl-Minku
Hello there! Minku is a version control system inpired by the basic working principles of git, but it works differently from git in many ways.

## Steps to run Minku program.
1. Run the following script in gcc compiler in the directory which consists of the clone of this repository-
```
gcc .\minkuControl.c .\initialiser.c .\st.c .\cmt.c .\getSHA1.c .\sha1.c -o minkuExecutable
```
2. Copy the created minkuExecutable.exe file to a directory which you want to initialise as a minku repo or to an existing Minku repository. Let this directory be Directory1
3. Open terminal in Directory1 and run minkuExecutable.exe.
4. Your Minku program will run and a line "Tell minku what to do: " should appear in the terminal.
5. Use the given commands to talk to Minku.

## The commands Minku can understand as of now - 
1. ```minku_ini``` - Intialises a minku repository.
2. ```minku_st``` - Adds the current version of the files in Directory1 to the staging area.
3. ```minku_cmt``` - Makes a commit consisting of the latest staged version of each file present in the directory.
4. ```minku_quit``` / ```minku_exit``` - closes the minku application.

## Internal working process of Minku - 
1. When ```minku_init``` is called, it creates a directory ```.\.minku``` in the working directory, Directory1.
2. When ```minku_st``` is called, it creates directories in the path ```.\.minku\obj``` with names like that of the files present in the working directory, Directory1 and creates a file with name as the SHA-1 hash code of the content of the current version of file. Everytime ```minku_st``` function is called, a new file is created within ```.\.minku\obj\your_file_name``` for each changed file.
3. Whenever ```minku_cmt``` is called, a new directory is created within ```.\.minku\cmt``` with name as the commit number. In the directory ```.\.minku\cmt\your_commit_number```, directories are created with filenames of the files in Directory1. In this directory ```.\.minku\cmt\your_commit_number\your_object_name```, a file is created with the name as the SHA-1 hash code of the file_contents of the latest staged version of the file.

P.S. - kindly refer to the video explaining the flow of the Minku application - [video link](https://drive.google.com/file/d/1cssbuAtRKaDK5nf_3d9y3NoaDH7jbaY9/view)

## What are areas of improvement?
1. **Due to lack of time**, many important git features like reverting, branch handling and many other features are unavailable as of now. I will add them as soon as possible.
>I am planning to implement reverting in the following way - 
I would delete all files in the present directory and make new files with the names as direcotory names in the reverted commit number directory -  ```.\.minku\cmt\your_commit_number``` and set their file content equal to the the decrypted SHA-1 code of the name of file inside the directory ```.\.minku\cmt\your_commit_number\your_object_name```.
*Shortcomings - I just noticed today that SHA-1 hash code is a sigle side encryption method. It cannot be decrypted.*
If I could implement reverting, I could also implement for checking out to newer/ existing branches in a similar way.

2. Minku is applicontainscable on a directory which contains files only. It cannot read subdirectories.
3. Minku has character limits set at many inputs or file content sizes.
