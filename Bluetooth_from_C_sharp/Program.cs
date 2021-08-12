using System;
using System.IO.Ports;

namespace Bluetooth_from_C_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            serialPort1.PortName = "COM9";
            serialPort1.baudRate = 9600;
            try
            {
                if (!serialPort1.IsOpen) serialPort1.Open();
            }
            catch (Exception ex)
            {
                System.Console.WriteLine(ex.Message);
            }

            String messageToSend = "Hello from C#!";
            serialPort1.Write(messageToSend);
            serialPort1.Close();
        }
    }
}
