 
#include "Mimic.h"

bool is_The_Signal_Already_There(decode_type_t Prtcl, uint32_t Ad,uint32_t Cmd,uint32_t Rwdata,uint32_t Bt);
{
	bool found = false;
	for (int i = 0; i < 8; i++)
	{    
		if (Protocol[i] == Prtcl && Address[i] == Ad && Command[i] == Cmd && RawData[i] == Rwdata && Bit[i] == Bt)
		{
			found = true;
		}

	}   

	if (found)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void mimic_Initialization();
{
	for(int i = 0; i < 8; i++)
	{ 
		if(button_Array[i] == 34 || button_Array[i] == 35 || button_Array[i] == 15 )
		{
			pinMode(button_Array[i],INPUT);

		}
		else
	{
			pinMode(button_Array[i],INPUT_PULLUP);

		}

	}
	// Start IR receiver (with internal LED feedback on built-in LED if desired)
	IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK);

	// Start IR sender
	IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);  // Feedback blinks built-in LED



	Serial.println("Mimic Deployed");
}

void what_deployed_mimic_does_is();
{
	if (IrReceiver.decode()) {  // Something was detected

		// Filter out obvious noise / empty triggers
		if (IrReceiver.decodedIRData.numberOfBits == 0 ||
			IrReceiver.decodedIRData.numberOfBits < 10) {  // Adjust threshold if needed (e.g. 14, 20)
			IrReceiver.resume();
			return;  // Silent ignore - no print, no storage
		}

		if (is_The_Signal_Already_There(IrReceiver.decodedIRData.protocol,
				  IrReceiver.decodedIRData.address,
				  IrReceiver.decodedIRData.command,
				  IrReceiver.decodedIRData.decodedRawData,
				  IrReceiver.decodedIRData.numberOfBits))
		{
			Serial.println("the signal is already present will not record twice");
			return;
		}

		if (!(signalCount<8))
		{
			Serial.println("maximum number of signal recorded cannot proceed further");
			return;
		}

		// Now it's probably real (or at least worth looking at)
		Protocol[signalCount] = IrReceiver.decodedIRData.protocol;
		Address[signalCount]  = IrReceiver.decodedIRData.address;
		Command[signalCount]  = IrReceiver.decodedIRData.command;
		RawData[signalCount]  = IrReceiver.decodedIRData.decodedRawData;

		if (IrReceiver.decodedIRData.protocol == SONY)
		{
			Bit[signalCount] = IrReceiver.decodedIRData.numberOfBits;
		}

		// Print only meaningful ones
		Serial.println("--- Received IR Code ---");
		Serial.print("Protocol: "); Serial.println(getProtocolString(Protocol[signalCount]));
		Serial.print("Address: 0x"); Serial.println(Address[signalCount], HEX);
		Serial.print("Command: 0x"); Serial.println(Command[signalCount], HEX);
		Serial.print("Raw Data: 0x"); Serial.println(RawData[signalCount], HEX);
		Serial.print("Bits: "); Serial.println(IrReceiver.decodedIRData.numberOfBits);

		Serial.println("------------------------");

		signalCount++;

		IrReceiver.resume();  // Always resume after processing
	}

	for(int i = 0; i < 8; i++)
	{
		if (digitalRead(button_Array[i]) == LOW ) {
			Serial.println("Replaying last captured code...");
			switch (Protocol[i]) {
				case NEC:
					IrSender.sendNEC(Address[i], Command[i], 0); // 0 repeats
					break;
				case SONY:
					IrSender.sendSony(Address[i], Command[i], Bit[i]);
					break;
				case RC5:
					IrSender.sendRC5(Address[i], Command[i], 0);
					break;
				case RC6:
					IrSender.sendRC6(Address[i], Command[i], 0);
					break;
				case SAMSUNG:
					IrSender.sendSamsung(Address[i], Command[i], 0);
					break;
				case LG:
					IrSender.sendLG(Address[i], Command[i], 0);
					break;
				default:
					Serial.println("Unsupported protocol for replay - using raw send.");
					break;
			}

		}
		delay(60); // Slightly longer to reduce loop spam
	}
}
