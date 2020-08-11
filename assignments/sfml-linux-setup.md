# SFML Linux Set-up

Courtesy of Robert Șolcă

## Building SFML on Linux 🐧

These are the steps for Fedora 32. If you have another distro that is using another package manager you can go to [this site](https://pkgs.org/) and you can search the packages there. It has what and where the package manager installs the files and also what is the command that you need to use to install the package.

## Dependencies

Taken from [documentation](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php).

- freetype
- x11
- xrandr
- udev
- opengl
- flac
- ogg
- vorbis
- vorbisenc
- vorbisfile
- openal
- pthread

You need both normal and development packages.  
Most of them are installed by default. The simplest way of finding what packages you are missing is to simply run cmake and see what errors you get.

### Installing dependencies

Fedora 32 comes with 4 missing dependencies. To install them use the following:

```sh
sudo dnf install systemd-devel
sudo dnf install openal-soft-devel-1.19.1-5.fc32.x86_64
sudo dnf install libvorbis-devel
sudo dnf install flac-devel-1.3.3-2.fc32.x86_64
```

If you don't find one of these packages it means that there is a new version out. Go to [this site](https://pkgs.org/) and search for how the package is named.  
After installing the missing dependencies you should be able to run cmake with out problems. If you know you've installed a package (both normal and development) and you get an error that says the package could not be found try to use flags and give the path manually.
