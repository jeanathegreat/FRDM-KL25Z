#include "stdafx.h"
#include <string>
#include <stdio.h>

#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

#pragma once

namespace App_WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Linq;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		delegate void SetTextDelegate(String ^Text);
	public:
		
		Form1(void)
		{
			InitializeComponent();
			InitializeShit();
			//
			//TODO: Add the constructor code here
			//		
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::Button^  btn_OpenPort;
	private: System::Windows::Forms::TextBox^  txt_SendMessage;


	private: System::Windows::Forms::Button^  btn_TakePic;
	private: System::Windows::Forms::Button^  btn_ReadJpegSize;
	private: System::Windows::Forms::Button^  btn_ReadJpgContent;
	private: System::Windows::Forms::Button^  btn_StopTakePic;
	private: System::Windows::Forms::Button^  btn_ClosePort;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txt_Status;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txt_RcvMessage;
	private: System::Windows::Forms::Button^  btn_Send;
	private: System::Windows::Forms::Button^  btn_Read;




	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//string message_disp;
		String^ in;
		//std::string writetoFile;
		String^ pathofFile;
		System::Windows::Forms::Button^  btn_Reset;
		FileStream^ swriter;
		int flag_to_write_file;
	private: System::Windows::Forms::Button^  button1;
			 array <System::Byte>^ churvs;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->btn_OpenPort = (gcnew System::Windows::Forms::Button());
			this->txt_SendMessage = (gcnew System::Windows::Forms::TextBox());
			this->btn_TakePic = (gcnew System::Windows::Forms::Button());
			this->btn_ReadJpegSize = (gcnew System::Windows::Forms::Button());
			this->btn_ReadJpgContent = (gcnew System::Windows::Forms::Button());
			this->btn_StopTakePic = (gcnew System::Windows::Forms::Button());
			this->btn_ClosePort = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_Status = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_RcvMessage = (gcnew System::Windows::Forms::TextBox());
			this->btn_Send = (gcnew System::Windows::Forms::Button());
			this->btn_Read = (gcnew System::Windows::Forms::Button());
			this->btn_Reset = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 38400;
			this->serialPort1->PortName = L"COM1";
			this->serialPort1->ReadBufferSize = 65536;
			this->serialPort1->ReadTimeout = 0;
			this->serialPort1->WriteTimeout = 1;
			this->serialPort1->Encoding = Encoding::GetEncoding(1252);
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// btn_OpenPort
			// 
			this->btn_OpenPort->Location = System::Drawing::Point(232, 30);
			this->btn_OpenPort->Name = L"btn_OpenPort";
			this->btn_OpenPort->Size = System::Drawing::Size(110, 23);
			this->btn_OpenPort->TabIndex = 0;
			this->btn_OpenPort->Text = L"Init Port";
			this->btn_OpenPort->UseVisualStyleBackColor = true;
			this->btn_OpenPort->Click += gcnew System::EventHandler(this, &Form1::btn_OpenPort_Click);
			// 
			// txt_SendMessage
			// 
			this->txt_SendMessage->Location = System::Drawing::Point(25, 105);
			this->txt_SendMessage->Multiline = true;
			this->txt_SendMessage->Name = L"txt_SendMessage";
			this->txt_SendMessage->Size = System::Drawing::Size(191, 176);
			this->txt_SendMessage->TabIndex = 1;
			// 
			// btn_TakePic
			// 
			this->btn_TakePic->Location = System::Drawing::Point(439, 55);
			this->btn_TakePic->Name = L"btn_TakePic";
			this->btn_TakePic->Size = System::Drawing::Size(110, 23);
			this->btn_TakePic->TabIndex = 2;
			this->btn_TakePic->Text = L"Take Picture";
			this->btn_TakePic->UseVisualStyleBackColor = true;
			this->btn_TakePic->Click += gcnew System::EventHandler(this, &Form1::btn_TakePicture_Click);
			// 
			// btn_ReadJpegSize
			// 
			this->btn_ReadJpegSize->Location = System::Drawing::Point(439, 84);
			this->btn_ReadJpegSize->Name = L"btn_ReadJpegSize";
			this->btn_ReadJpegSize->Size = System::Drawing::Size(110, 23);
			this->btn_ReadJpegSize->TabIndex = 3;
			this->btn_ReadJpegSize->Text = L"Read Jpeg";
			this->btn_ReadJpegSize->UseVisualStyleBackColor = true;
			this->btn_ReadJpegSize->Click += gcnew System::EventHandler(this, &Form1::btn_ReadJpegSize_Click);
			// 
			// btn_ReadJpgContent
			// 
			this->btn_ReadJpgContent->Location = System::Drawing::Point(439, 114);
			this->btn_ReadJpgContent->Name = L"btn_ReadJpgContent";
			this->btn_ReadJpgContent->Size = System::Drawing::Size(110, 23);
			this->btn_ReadJpgContent->TabIndex = 4;
			this->btn_ReadJpgContent->Text = L"Read Jpg Content";
			this->btn_ReadJpgContent->UseVisualStyleBackColor = true;
			// 
			// btn_StopTakePic
			// 
			this->btn_StopTakePic->Location = System::Drawing::Point(439, 144);
			this->btn_StopTakePic->Name = L"btn_StopTakePic";
			this->btn_StopTakePic->Size = System::Drawing::Size(110, 23);
			this->btn_StopTakePic->TabIndex = 5;
			this->btn_StopTakePic->Text = L"Stop Pic";
			this->btn_StopTakePic->UseVisualStyleBackColor = true;
			this->btn_StopTakePic->Click += gcnew System::EventHandler(this, &Form1::btn_StopTakePic_Click);
			// 
			// btn_ClosePort
			// 
			this->btn_ClosePort->Enabled = false;
			this->btn_ClosePort->Location = System::Drawing::Point(232, 59);
			this->btn_ClosePort->Name = L"btn_ClosePort";
			this->btn_ClosePort->Size = System::Drawing::Size(110, 23);
			this->btn_ClosePort->TabIndex = 6;
			this->btn_ClosePort->Text = L"Close Port";
			this->btn_ClosePort->UseVisualStyleBackColor = true;
			this->btn_ClosePort->Click += gcnew System::EventHandler(this, &Form1::btn_ClosePort_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Status:";
			// 
			// txt_Status
			// 
			this->txt_Status->Enabled = false;
			this->txt_Status->Location = System::Drawing::Point(25, 33);
			this->txt_Status->Name = L"txt_Status";
			this->txt_Status->Size = System::Drawing::Size(191, 20);
			this->txt_Status->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Enter message:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(239, 171);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Message received:";
			// 
			// txt_RcvMessage
			// 
			this->txt_RcvMessage->Enabled = false;
			this->txt_RcvMessage->Location = System::Drawing::Point(232, 189);
			this->txt_RcvMessage->Multiline = true;
			this->txt_RcvMessage->Name = L"txt_RcvMessage";
			this->txt_RcvMessage->Size = System::Drawing::Size(191, 92);
			this->txt_RcvMessage->TabIndex = 10;
			// 
			// btn_Send
			// 
			this->btn_Send->Enabled = false;
			this->btn_Send->Location = System::Drawing::Point(232, 105);
			this->btn_Send->Name = L"btn_Send";
			this->btn_Send->Size = System::Drawing::Size(110, 23);
			this->btn_Send->TabIndex = 12;
			this->btn_Send->Text = L"Send";
			this->btn_Send->UseVisualStyleBackColor = true;
			this->btn_Send->Click += gcnew System::EventHandler(this, &Form1::btn_Send_Click);
			// 
			// btn_Read
			// 
			this->btn_Read->Enabled = false;
			this->btn_Read->Location = System::Drawing::Point(439, 187);
			this->btn_Read->Name = L"btn_Read";
			this->btn_Read->Size = System::Drawing::Size(110, 23);
			this->btn_Read->TabIndex = 13;
			this->btn_Read->Text = L"Read";
			this->btn_Read->UseVisualStyleBackColor = true;
			this->btn_Read->Click += gcnew System::EventHandler(this, &Form1::btn_Read_Click);
			// 
			// btn_Reset
			// 
			this->btn_Reset->Location = System::Drawing::Point(439, 26);
			this->btn_Reset->Name = L"btn_Reset";
			this->btn_Reset->Size = System::Drawing::Size(110, 23);
			this->btn_Reset->TabIndex = 14;
			this->btn_Reset->Text = L"Reset";
			this->btn_Reset->UseVisualStyleBackColor = true;
			this->btn_Reset->Click += gcnew System::EventHandler(this, &Form1::btn_Reset_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(296, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 307);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn_Reset);
			this->Controls->Add(this->btn_Read);
			this->Controls->Add(this->btn_Send);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_RcvMessage);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_Status);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_ClosePort);
			this->Controls->Add(this->btn_StopTakePic);
			this->Controls->Add(this->btn_ReadJpgContent);
			this->Controls->Add(this->btn_ReadJpegSize);
			this->Controls->Add(this->btn_TakePic);
			this->Controls->Add(this->txt_SendMessage);
			this->Controls->Add(this->btn_OpenPort);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void InitializeShit(void)
			 {
				this->pathofFile = "C:\\temp\\file.dat";
				flag_to_write_file = 0;
			 }

	//for DataReceived Event SerialPort
	private: void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
			{
				int rcv_size = 0;
					try
					{					
						this->swriter = gcnew FileStream(pathofFile, FileMode::Append, FileAccess::Write);
						in = this->serialPort1->ReadExisting();
						rcv_size = in->Length;
						Encoding^ enc = Encoding::GetEncoding("Windows-1252"); 
						churvs = enc->GetBytes(in);

						if(rcv_size == 9)
						{
							Char xl = in->default[ --rcv_size ];
							Char xh = in->default[ --rcv_size ];

							auto cam_read = gcnew array<System::Char> { 0x56,0x00,0x32,0x0C,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,xh,xl,0x00,0x0A };
							this->serialPort1->Write(cam_read, 0, cam_read->Length);
						}

							this->swriter->Write(churvs, 0, churvs->Length);
							this->swriter->Close();

					}catch(TimeoutException^){
						in ="Timeout Exception";
					}
			}

	private: System::Void btn_OpenPort_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			
				try
				{
				// make sure port isn't open	
					if(!this->serialPort1->IsOpen)
					{						
						//open serial port 
						this->serialPort1->Open();	
						//write Status
						this->txt_Status->Text = "Port successfully opened.";

						//Enable btn_ClosePort, btn_Send, btn_Read
						this->btn_ClosePort->Enabled = true;
						this->btn_Send->Enabled = true;
						this->btn_Read->Enabled = true;

						//disable btn_OpenPort
						this->btn_OpenPort->Enabled = false;
					}else
						this->txt_Status->Text="Port isn't opened";
				}catch(UnauthorizedAccessException^){
					this->txt_Status->Text="Unauthorized Access";
				}
			}

	//Take Picture button
	private: System::Void btn_TakePicture_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				auto mess_takePic = gcnew array<System::Byte> { 0x56,0x00,0x36,0x01,0x00 };
				
				if(this->serialPort1->IsOpen)
					this->serialPort1->Write(mess_takePic, 0, mess_takePic->Length);
				
				else
					this->txt_Status->Text="Port Not Opened";
			}

	//Stop Take Pic button
	private: System::Void btn_StopTakePic_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				auto mess_stoptakePic = gcnew array<System::Byte> { 0x56,0x00,0x36,0x01,0x03 };

				if(this->serialPort1->IsOpen)
					this->serialPort1->Write(mess_stoptakePic, 0, mess_stoptakePic->Length);
				else
					this->txt_Status->Text="Port Not Opened";
			}

	//Send Read jpeg file size command
	private: System::Void btn_ReadJpegSize_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				auto mess_readjpegsize = gcnew array<System::Byte> { 0x56,0x00,0x34,0x01,0x00 };

				if(this->serialPort1->IsOpen)
					this->serialPort1->Write(mess_readjpegsize, 0, mess_readjpegsize->Length);
				else
					this->txt_Status->Text="Port Not Opened";
			}

	//Close port
	private: System::Void btn_ClosePort_Click(System::Object^  sender, System::EventArgs^  e)
			{
				if(this->serialPort1->IsOpen)
				{
					//close serialPort
					this->serialPort1->Close();

					//enable btn_OpenPort
					this->btn_OpenPort->Enabled = true;

					//disable btn_Read, btn_Send, btn_ClosePort
					this->btn_Read->Enabled = false;
					this->btn_ClosePort->Enabled = false;
					this->btn_Send->Enabled = false;

					//display status
					this->txt_Status->Text="Port sucessfully closed";
				}else{
					//display status
					this->txt_Status->Text="Cannot close";
				}

			}

	private: System::Void btn_Send_Click(System::Object^  sender, System::EventArgs^  e)
			{
				auto mess_takePic = gcnew array<System::Byte> { 0xFF,0xFE,0xFF };
				String^ message = this->txt_SendMessage->Text;
				if(this->serialPort1->IsOpen)
					//this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));
					try{
						//this->serialPort1->Write(message);
						this->serialPort1->Write("ÿØÿþ");
						//this->serialPort1->Write(mess_takePic, 0, mess_takePic->Length);
					}catch(TimeoutException^){
						this->txt_Status->Text = "Cannot click Send button twice. Click Read button first.";
					}
					//this->serialPort1->Write(message, 0, message->Length);
					//this->serialPort1->Write(message);
				 else
					this->txt_Status->Text="Port Not Opened";
			}

private: System::Void btn_Read_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				// check if port is ready for reading
				if(this->serialPort1->IsOpen){
						this->txt_RcvMessage->Text = in;
				}
				else
					// give error warning
					this->txt_Status->Text="Port Not Opened";
			}

private: System::Void btn_Reset_Click(System::Object^  sender, System::EventArgs^  e) {
				auto mess_takePic = gcnew array<System::Char> { 0x56,0x00,0x26,0x00 };
				String^ message = this->txt_SendMessage->Text;
				if(this->serialPort1->IsOpen)
					
					try{						
						this->serialPort1->Write(mess_takePic, 0, mess_takePic->Length);
					}catch(TimeoutException^){
						this->txt_Status->Text = "Cannot click Send button twice. Click Read button first.";
					}
				else
					this->txt_Status->Text="Port Not Opened";
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			array <Byte>^ heller = File::ReadAllBytes(pathofFile);

			int i, first, last, sizeofnew;
			//first = Array::IndexOf(heller, 255);
			first = 14;
			//for(i = heller->Length - 1; i > heller->Length/2; i--)
			//	if(heller[i] == 0xD9) break;
			last = heller->Length - 6;
			sizeofnew = last-first;
			
			array <Byte>^ jpegfile = gcnew array <Byte> (++sizeofnew);
			Array::Copy(heller, first, jpegfile, 0, sizeofnew);
			FileStream^ lala = gcnew FileStream("C:\\temp\\chur.jpg", FileMode::Append, FileAccess::Write);
			lala->Write(jpegfile, 0, jpegfile->Length);
			lala->Close();
		 }

void SetText(String^ text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this->txt_RcvMessage->InvokeRequired)
            {
                SetTextDelegate^ d = gcnew SetTextDelegate(this, &Form1::SetText);
                this->Invoke(d, gcnew array<Object^> { text });
            }
            else
            {
                this->txt_RcvMessage->Text = text;
            }
        }


};
}

