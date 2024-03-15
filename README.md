# Assignment-4

Here are the contents of my tasks.json file:

{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build entire project",
            "command": "C:\\Program Files\\MinGW\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-std=c++11",
                "${workspaceFolder}\\Lepton.cpp",
                "${workspaceFolder}\\Detector.cpp",
                "${workspaceFolder}\\main.cpp",
                "-o",
                "${workspaceFolder}\\project.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Custom task to build the entire project."
        }
    ],
    "version": "2.0.0"
}
