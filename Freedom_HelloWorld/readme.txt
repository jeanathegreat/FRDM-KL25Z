readme.txt
----------
This is an example project for the Freescale Freedom board (Kinetis KL25Z Freedom Board).
Features:
- Using UART0 (routed to the OpenSDA virtual CDC port)
- Writes a hello world string
- Waits for correct characters to enable red, or green LED, or both, or disables the two LEDs.
- Commands are:
	(1) "Red*\n" - turns red LED on
	(2) "Green*\n" - turns green LED on
	(3) "Off*\n" - turns both green and red LED off
	(4) Any other string - turns both green and red LED on
-Depending on the commands, there are corresponding return characters
	(1) "Red*\n" - returns "Okayr*\r\n"
	(2) "Green*\n" - returns "Okayg*\r\n"
	(3) "Off*\n" - returns "Okayo*\r\n"
	(4) Any other string - returns "Okayo*\r\n"
Toolchain: 
- CodeWarrior for MCU10.3

Components:
- LED
- Wait

More information: http://mcuoneclipse.wordpress.com/:
- http://mcuoneclipse.com/2012/10/14/tutorial-printf-and-hello-world-with-the-freedom-kl25z-board/
- http://mcuoneclipse.com/2013/04/17/printf-with-the-frdm-kl25z-board-and-without-processor-expert/
