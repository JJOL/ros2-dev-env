# ROS2 Packages Dev Envioronment Sample

## Setup Instructions
### Environment Setup
Follow Guide Steps: "Installing WSL2 Distro" and "Installing ROS2 Galactic"
[WSL2 OS Setup and Installation Required](https://drive.google.com/file/d/1kD5Oyv9vA1krtQ5omYh6aPYO40oc63-4/view?usp=share_link)

### Obtaining Code
```console
cd ~
git clone https://github.com/JJOL/ros2-dev-env.git
cd ros2-dev-env
```

### Running
```console
source /opt/ros/galactic/setup.bash
colcon build
source install/setup.bash
ros2 run demo_pkg demo
```