from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    hostname = "192.168.1.12"
    buffer_size = 200
    topic_namespace = "vicon_unlabeled_markers"

    return LaunchDescription(
        [
            Node(
                package="vicon_receiver",
                executable="vicon_client_unlabeled",
                output="screen",
                parameters=[
                    {
                        "hostname": hostname,
                        "buffer_size": buffer_size,
                        "namespace": topic_namespace,
                    }
                ],
            )
        ]
    )
