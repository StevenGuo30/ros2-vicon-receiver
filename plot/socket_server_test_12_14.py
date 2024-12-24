import socket
import numpy as np
import time

# Server configuration
Host, Port = "localhost", 12345


class MyServer:
    counter = 0

    def update_data(self):
        """Generate data to be sent periodically."""
        temp_new = np.array(
            [
                [1.1823136303447663, 36.59373070071932, -0.15070220641620874],
                [-0.11586563896642983, 60.591261973667656, 0.7435437497910018],
                [0.14706634107515376, 86.57817800605058, 0.030472402101370352],
                [0.3664661709528736, 114.34573219942308, -0.5246268908459925],
                [1.0790936927569983, 141.40869830957436, -0.5480697262501174],
                [1.363622637459471, 171.35692373588466, -0.3537093114006389],
            ]
        )
        temp_flicker = np.array(
            [
                [1.1823136303447663, 36.59373070071932, -0.15070220641620874],
                [-0.11586563896642983, 60.591261973667656, 0.7435437497910018],
                [0.14706634107515376, 86.57817800605058, 0.030472402101370352],
                [0.3664661709528736, 114.34573219942308, -0.5246268908459925],
                [1.363622637459471, 171.35692373588466, -0.3537093114006389],
            ]
        )

        if MyServer.counter % 4 != 0:
            data = temp_new + 0.1 * (MyServer.counter % 6)
        else:
            data = temp_flicker
        MyServer.counter += 1
        return data

    def periodic_send(self, socket, interval=1.0):
        """Periodically send data to all connected clients."""
        while True:
            try:
                data = self.update_data()
                x, y, z = data[:, 0], data[:, 1], data[:, 2]
                x_str = np.array2string(x, separator=",")
                y_str = np.array2string(y, separator=",")
                z_str = np.array2string(z, separator=",")
                message = f'{{"x": {x_str}, "y": {y_str}, "z": {z_str}}}\n'
                # socket.sendall(bytes(message, "utf-8"))
                
                socket.sendall(message.encode("utf-8"))
                print(f"Sent data: {message}")
                time.sleep(interval)
            except Exception as e:
                print(f"Error sending data: {e}")
                socket.close()


if __name__ == "__main__":
    # Create and start the server
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((Host, Port))
    print(f"Server started at {Host}:{Port}")
    sock.listen(
        1
    )  # Listen for incoming connections，Here 1 means only one connection is allowed
    conn, addr = sock.accept()  # Accept a connection
    sock.settimeout(None)
    print(f"Connected to {addr}")
    myserver = MyServer()
    try:
        print("Sending data periodically.")
        while True:
            myserver.periodic_send(conn)
    except KeyboardInterrupt:
        print("KeyboardInterrupt received, shutting down.")
        conn.close()
        sock.close()
