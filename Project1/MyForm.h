#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public value struct Options {
		Color bg_color;
		String^ bg_image;
	};

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{



	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(617, 423);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(210, 441);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"<";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(372, 441);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L">";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(291, 441);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"try";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 474);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		l_shift(false);
		show_slide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		r_shift(false);
		show_slide();
	}
	private: System::Void r_shift(bool is_changed) {
		current_slide = current_slide + 1 < slides->Length ? ++current_slide : current_slide;
		Options^ ops = TryOptions(slides[current_slide]);

		if (ops) {
			ApplyOptions(ops);
			r_shift(true);
			return;
		}
		else if (is_changed == false) {
			ApplyOptions(global_cfg);
		}

		show_slide();
	}
	private: System::Void l_shift(bool is_changed) {
		current_slide = current_slide > 0 ? --current_slide : current_slide;
		Options^ ops = TryOptions(slides[current_slide]);

		if (ops) {
			l_shift(false);
			return;
		}
		else if (current_slide > 0) {
			ops = TryOptions(slides[current_slide-1]);
			if (ops) {
				ApplyOptions(ops);
			}
			else {
				ApplyOptions(global_cfg);
			}
		}
		else {
			ApplyOptions(global_cfg);
		}

		show_slide();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
			return;

		button1->Enabled = true;
		button2->Enabled = true;

		String^ filename = openFileDialog1->FileName;
		String^ text = System::IO::File::ReadAllText(filename);
		MessageBox::Show("‘айл открыт");

		array<String^>^ sep = { "---" };
		this->slides = text->Split(sep, StringSplitOptions::None);

		if (this->slides->Length > 0) {
			this->global_cfg = TryOptions(this->slides[0]);
			this->current_cfg = this->global_cfg;
			ApplyOptions(this->global_cfg);

			if (this->global_cfg) {
				// slice up the slides
				// unfortunately there's no remove method
				array<String^>^ slides = gcnew array<String^>(this->slides->Length - 1);
				for (int i = 0; i < (slides->Length); i++) {
					slides[i] = this->slides[i + 1];
				}

				this->slides = slides;
			}
		}

		show_slide();
	}

	private: System::Void show_slide() {
		richTextBox1->Clear();
		String^ text = slides[current_slide];

		array<String^>^ sep = { Environment::NewLine + Environment::NewLine };
		for each (auto block in text->Split(sep, StringSplitOptions::RemoveEmptyEntries))
		{
			if (String::IsNullOrEmpty(block)) {
				continue;
			}

			if (block->StartsWith("###")) {
				array<Char>^ sep = { '#' };
				block = block->TrimStart(sep);
				AppendFormattedText(this->richTextBox1, block, Color::Black, false, HorizontalAlignment::Left, 13);
			}
			else if (block->StartsWith("##")) {
				array<Char>^ sep = { '#' };
				block = block->TrimStart(sep);
				AppendFormattedText(this->richTextBox1, block, Color::CadetBlue, true, HorizontalAlignment::Center, 10);
			}
			else if (block->StartsWith("#")) {
				array<Char>^ sep = { '#' };
				block = block->TrimStart(sep);
				AppendFormattedText(this->richTextBox1, block, Color::CadetBlue, true, HorizontalAlignment::Center, 20);
			}
			else if (block->StartsWith("[image](")) {
				String^ img = "[image](";
				block = block->Substring(img->Length);
				block = block->Remove(block->Length - 1);

				Image^ image = Image::FromFile(block);
				if (image != nullptr) {
					image = resizeImage(image, System::Drawing::Size(150, 150));
					Clipboard::SetImage(image);
					richTextBox1->Paste();
					richTextBox1->Select();
					richTextBox1->SelectionAlignment = HorizontalAlignment::Center;
					richTextBox1->SelectionLength = 0;
				}
			}
			else {
				AppendFormattedText(this->richTextBox1, block, Color::Black, false, HorizontalAlignment::Left, 10);
			}

			this->richTextBox1->AppendText("\n\n");
		}
	}

	private: Image^ resizeImage(Image^ imgToResize, System::Drawing::Size size)
	{
		return (Image^)(gcnew Bitmap(imgToResize, size));
	}

	private: System::Void AppendFormattedText(RichTextBox^ rtb, String^ text, Color textColour, Boolean isBold, HorizontalAlignment alignment, int fontSize)
	{
		int start = rtb->TextLength;
		rtb->AppendText(text);
		int end = rtb->TextLength; // now longer by length of appended text

		// Select text that was appended
		rtb->Select(start, end - start);

		rtb->SelectionColor = textColour;
		rtb->SelectionAlignment = alignment;
		rtb->SelectionFont = gcnew System::Drawing::Font(
			"Arial", fontSize,
			(isBold ? FontStyle::Bold : FontStyle::Regular));

		// Unselect text
		rtb->SelectionLength = 0;
	}

	private: Options^ TryOptions(String^ conf)
	{
		array<String^>^ sep = { "\n" };
		array<String^>^ options = conf->Split(sep, StringSplitOptions::RemoveEmptyEntries);
		if (options->Length == 0) {
			return nullptr;
		}

		for each (auto o in options) {
			if (!(o->StartsWith("@") || String::IsNullOrEmpty(o) || o == "\r")) {
				return nullptr;
			}
		}


		Options^ settings = gcnew Options{};
		for each (auto o in options) {
			o = o->Trim();
			String^ opt = "@bg_color: ";
			int index = o->IndexOf(opt);
			if (index >= 0) {
				String^ color = o->Substring(opt->Length);
				settings->bg_color = Color::FromName(color);
				continue;
			}

			opt = "@bg_image: ";
			index = o->IndexOf(opt);
			if (index >= 0) {
				String^ image_path = o->Substring(opt->Length);
				settings->bg_image = image_path;
				continue;
			}
		}

		return settings;
	}


	private: System::Void ApplyOptions(Options^ ops)
	{
		if (ops != nullptr) {
			richTextBox1->BackColor = ops->bg_color;
		}
	}

	private: array<String^>^ slides;
	private: int current_slide;
	private: Options^ global_cfg;
	private: Options^ current_cfg;
	};
}
