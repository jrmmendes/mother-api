# Mother API
ESP-IDF powered firmware to generate a REST API and WIFI access point.

[![GitHub issues](https://img.shields.io/github/issues/jrmmendes/mother_api)](https://github.com/jrmmendes/mother_api/issues)
[![GitHub license](https://img.shields.io/github/license/jrmmendes/mother_api)](https://github.com/jrmmendes/mother_api/blob/master/LICENSE)
![Language](https://img.shields.io/badge/langague-C-yellow)

## Project Setup
First of all, you'll need to install the [ESP-IDF](https://github.com/espressif/esp-idf) framework on your environment.

### Downloading and installing steps for Linux (Ubuntu/Debian):
1- Install the ESP-IDF dependencies on your system:
```sh
sudo apt-get install git wget flex bison gperf python python-pip python-setuptools python-serial python-click python-cryptography python-future python-pyparsing python-pyelftools cmake ninja-build ccache libffi-dev libssl-dev
```
2 - [Get ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#step-2-get-esp-idf):
```sh
mkdir ~/.esp && cd ~/.esp && git clone --recursive https://github.com/espressif/esp-idf.git 
```
3 - If you're using bash, add this to `.bashrc`. ZSH users must do the same to `.zshrc`:
```
# ESP-IDF
alias esp-activate="source $HOME/.esp/esp-idf/export.sh"
alias esp-init=cp -r $IDF_PATH/examples/get-started/hello_world .
```

Now you can run `esp-activate` on shell to export ESP-IDF system variables (like `IDF_PATH`). It will be required before compiling apps. You can also use `esp-init` to create a simples boilerplate based on the `hello_world` example.
