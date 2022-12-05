# ROSIE-Dev-Env
ROSIE Developer Environment

# Docker Image for the Helgen Rosie Developer Environment

## Pre-Requisites

### WSL2

WSL2 must be installed in Windows you can find how to install it [here](https://www.notion.so/helgen/Windows-Subsystem-For-Linux-2a55086df0364ed4b9fa5adc4f415bb4)

### Docker

Download and install the latest version of Docker from [here](https://www.docker.com/)

### VSCode

Get the latest VSCode version [here](https://code.visualstudio.com/download)

### VScode Extensions

Also this extensions are needed:

- [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
- [Remote Development](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)

## Installing

Clone this repository and open VSCode inside.

```bash

git@github.com:Helgen-Tech/ROSIE-Dev-Env.git

cd Rosie-Dev-Env

code .

```

Once VSCode has opened, you can just open the code inside a container. Make sure that you have Docker opened.

When the image finishes downloading / processing you are now in the Developer environment.

# Ubuntu Installation

## Prerequisites

- Install apt packages

```bash
sudo apt install ca-certificates curl gnupg lsb-release
```

- Add Dockers GPG Keys

```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```

- Set up the repository
```bash
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```
- Install docker

```bash
sudo apt install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

- Add your user to the Docker group
```bash
sudo usermod -a -G docker your-user-name
```

- Test the installation

```bash
sudo docker run hello-world
```

# How to ask for new packages to be added to the environment

First of all make sure that the you have tested locally the package(s) you want to add to the Developing Environment and that the are no conflicts.

Then you open a [new issue](https://github.com/Helgen-Tech/ROSIE-Dev-Env/issues/new) in the repo.

You have to give a little description of why the package is needed and where is going to be used.