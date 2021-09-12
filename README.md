# liblogg
Easy and fast logging library

## Getting Started
These instructions will get you a copy of the project and use it.

##  Build and Install
To build your need cmake and a c++ compiler installed in your system.
```
$ git clone https://github.com/ern123/logg.git
$ cd logg
$ mkdir build && cd build
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ..
$ cmake --build .
$ sudo cmake --install .
```

## Example
```
logg::logger l;
l.error("My Error Message");
l.log("A Log");
l.log(logg::LEVEL_DEBUG, "My Debug Message");
```
## Contributing
Contributors are alway welcome!, all pull request will be revised.

## License
This project is licensed under the LGPL License - see the [LICENSE](LICENSE) file for details.

## Author
Ern <ern8642@gmail.com>
