import socket
import rclpy
from rclpy.node import Node
from vicon_receiver.msg import MarkersList
import threading
import numpy as np
import time


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
            sock.settimeout(None)
            print(f"Connected to {addr}")
        except KeyboardInterrupt:
            self.server.close()
            sock.close()
            self.get_logger().info("KeyboardInterrupt received, shutting down.")

    def callback(self, msg):
        x = np.array(msg.x)
        y = np.array(msg.y)
        z = np.array(msg.z)
        x_str = np.array2string(x, separator=",")
        y_str = np.array2string(y, separator=",")
        z_str = np.array2string(z, separator=",")
        print(x_str)
        print(y_str)
        print(z_str)
        message = f'{{"x": {x_str}, "y": {y_str}, "z": {z_str}}}||'
        # try:
        self.server.send(message.encode("utf-8"))
        print(f"send {message}")
        self.server.recv(1024)
        print(f"recved")

        self.get_logger().info(f"Sent data to socket: {message}")
        # except Exception as e:
        #     self.get_logger().info(f"Error sending data to socket: {e}")
        #     self.get_logger().info(f"Received {message}")
        #     raise Exception

        # self.count = self.count % 1
        # else:
        #     self.server.sendall("tests".encode("utf-8"))
        #     self.get_logger().info(f"Sent test data to socket")
        # time.sleep(1)


if __name__ == "__main__":
    rclpy.init()
    My_ros_socket_node = ros_socket_node()
    rclpy.spin(My_ros_socket_node)
    rclpy.shutdown()
