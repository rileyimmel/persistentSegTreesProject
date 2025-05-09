# persistentSegTreesProject
For CS4501 Adv Algo at UVA. Persistent Segment Trees final project

## Requirments:
https://markfloryan.github.io/advalgo_projects/requirements.html
1) Executive Summary: 4-8 page description of everything that has been delivered in this packet / project.
2) Implementation: In C++, Java, and Python. The code needs to be thoroughly commented.
3) Instructional Slides: Two sets of instructional slides. The first, a thorough, well designed, informative slideset that briefly teach the topic to an advanced undergraduate audience (about one lecture or 10-15 slides in length). A second, shorter, set of slides will be submitted that will be used for your 10 minute presentation.
4) PC: Custom Programming Challenge: A programming assignment that asks students to use the algorithm in question, but with at least one notable twist / change to the topic / algorithm in question.
5) PC Test Cases: At least 20 test cases that cover likely edge cases and test for speed / efficiency.
6) PC Solution: A solution to your custom PC in all three languages (C++, Java, Python).

## Links
1) Executive Summary: https://docs.google.com/document/d/1_NnYsMi_02FXpwYzapc8alG_G4ykaGeHsiYMpPcrwyE/edit?usp=sharing
2) Full Slides: https://myuva-my.sharepoint.com/:p:/r/personal/ypq8st_virginia_edu/Documents/persistentSegTrees.pptx?d=w41e035c359114248bf5a8c01e4a635e7&csf=1&web=1&e=4BYPwF
3) Short Slides: https://myuva-my.sharepoint.com/:p:/r/personal/ypq8st_virginia_edu/Documents/persistentSegTreesPresentaion.pptx?d=w7c609d6c7df54504ba63db117a4454ad&csf=1&web=1&e=wc23b4

## Implementation

These do not currently take input from the user as they are simply examples of an implementation of the data structure.
They do, however, include sample cases to showcase their functionality. These sample cases can be observed by running
program (ex. for C++, running ./pst will print out the results of the sample cases).

### C++
**Filename:** `PST.cpp` </br>
**Requirements:** C++ 11+ and CMake (make sure `cmake` is on your `$PATH`))

```bash
# from the repo root
cd Implementations/C++
# create a build directory
mkdir build
# cd into it
cd build
# run cmake to generate the makefile
cmake ..
# build the project
make
# run the demo
./pst ../../io/sample.in.# ../../io/sample.out.#
```

### Java
**Filenames:** `Main.java`, `PST.java`, `Node.java`  
**Requirements:** JDK 11+ (make sure `java` & `javac` are on your `$PATH`)

```bash
# from the repo root
cd Implementations/Java
# compile all sources
javac *.java
# run the demo
java Main ../io/sample.in.# ../io/sample.out.#
```

### Python
**Filenames:** `PST.py`, `Node.py`
**Requirements:** Python 3+
```bash
# from the repo root
cd Implementations/Python
# run the demo
python3 Main.py ../io/sample.in.# ../io/sample.out.#
```

