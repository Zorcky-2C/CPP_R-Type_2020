#!/usr/bin/env bash
unameOut="$(uname -s)"

if [ "$unameOut" = "Linux" ]; then
    sudo apt install python3-pip
    sudo dnf install python3-pip
    sudo pip3 install conan
    conan remote add conan https://api.bintray.com/conan/conan/conan-center
    conan remote add epitech : https://bintray.com/epitech/public-conan
    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

    conan profile update settings.cppstd=17 default

    rm -rf build && mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .

else
    echo "WINDOWS"
	echo "Files initiation ..."
	mkdir x64
	mkdir x64/Release
	cp -Rf src/client/asset x64/Release/
	cp -Rf src/client/myasset x64/Release/
	cp -f monsters x64/Release/
	cp -f launchServer.sh x64/Release/

	echo "initiation finished."

    conan remote add r-Type https://api.bintray.com/conan/bincrafters/public-conan

    conan install . --build=missing

fi