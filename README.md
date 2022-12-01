# ROS2 Packages Dev Envioronment Sample

## Setup Instructions
### Environment Setup
Follow Guide Steps: "Installing WSL2 Distro" and "Installing ROS2 Galactic"
[WSL2 OS Setup and Installation Required]()

### Obtaining Code
```console
cd ~
git clone <this repo>
cd <repo folder>
```

### Running
```console
source /opt/ros/galactic/setup.bash
colcon build
source install/setup.bash
ros2 run demo_pkg demo
```