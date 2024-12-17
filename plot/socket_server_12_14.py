import socket
import rclpy
from rclpy.node import Node
from vicon_receiver.msg import MarkersList
import threading
import numpy as np


class ros_socket_node(Node):
    def __init__(self):
        super().__init__("ros_socket_node")
        self.topic_name = (
            "/vicon_unlabeled_markers/unlabeled_markers/positions_velocity"
        )
        self.create_subscription(
            MarkersList,
            self.topic_name,
            self.callback,
            10,
        )  # Number 10 is the queue size
        self.get_logger().info(f"Subscribed to topic: {self.topic_name}")
        Host, Port = "localhost", 12345
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.count = 0
        try:
            sock.bind((Host, Port))
            print(f"Server started at {Host}:{Port}")
            sock.listen(1)
            self.server, addr = sock.accept()
            print(f"Connected to {addr}")
        except KeyboardInterrupt:
            self.server.close()
            sock.close()
            self.get_logger().info("KeyboardInterrupt received, shutting down.")

    def callback(self, msg):
        if self.count % 100 == 0:  # downsample, send every 100th message
            x = np.array(msg.x[0])
            y = np.array(msg.y[0])
            z = np.array(msg.z[0])
            x_str = np.array2string(x, separator=",")
            y_str = np.array2string(y, separator=",")
            z_str = np.array2string(z, separator=",")
            data = f'{{"x": {x_str}, "y": {y_str}, "z": {z_str}}}\n'
            try:
                self.server.sendall(data.encode("utf-8"))
                self.get_logger().info(f"Sent data to socket: {data}")
            except Exception as e:
                self.get_logger().info(f"Error sending data to socket: {e}")
        self.count = self.count % 100
        self.count += 1


if __name__ == "__main__":
    rclpy.init()
    My_ros_socket_node = ros_socket_node()
    rclpy.spin(My_ros_socket_node)
    rclpy.shutdown()
