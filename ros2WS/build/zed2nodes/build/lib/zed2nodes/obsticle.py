import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class DistanceCalculator(Node):
    def __init__(self):
        super().__init__('distance_calculator')
        self.bridge = CvBridge()
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        if depth_image is not None:
            x, y = self.target_

def main(args=None):
    rclpy.init(args=args)
    node = DistanceCalculator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()