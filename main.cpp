#include <exception>

#include "system/codeporting_translator_cs2cpp_framework.h"
#include "system/console.h"
#include "system/exceptions.h"

#include "Aspose.PDF.Cpp/Text/TextFragmentAbsorber.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/Color.h"
#include "Aspose.PDF.Cpp/Text/FontRepository.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Generator/Paragraphs.h"
#include "Aspose.PDF.Cpp/Text/FontStyles.h"
#include "Aspose.PDF.Cpp/Text/TextFragment.h"
#include "Aspose.PDF.Cpp/Text/TextFragmentCollection.h"
#include "Aspose.PDF.Cpp/Text/TextFragmentState.h"
#include "Aspose.PDF.Cpp/Text/TextParagraph.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;
using namespace Aspose::Pdf::Text;

int cnt_of_changes;

void ReplaceTextOnAllPages(System::String phrase_to_change, System::String changed_phrase) {

    String _dataDir(u"E:\\g-soh\\Project1\\Project1\\");

    auto document = MakeObject<Document>(_dataDir + u"workpls.pdf");

    // Create TextAbsorber object to find all instances of the input search phrase
    auto textFragmentAbsorber = MakeObject<TextFragmentAbsorber>(phrase_to_change);

    // Accept the absorber for first page of document
    document->get_Pages()->Accept(textFragmentAbsorber);

    // Get the extracted text fragments into collection
    auto textFragmentCollection = textFragmentAbsorber->get_TextFragments();

    // Loop through the fragments
    for (auto textFragment : textFragmentCollection) {
        // Update text and other properties
        textFragment->set_Text(changed_phrase);
        textFragment->get_TextState()->set_Font(FontRepository::FindFont(u"Verdana"));
        textFragment->get_TextState()->set_FontSize(12);
        //textFragment->get_TextState()->set_ForegroundColor(Color::get_Blue());
        //textFragment->get_TextState()->set_BackgroundColor(Color::get_Gray());
    }
    // Save the updated PDF file
    document->Save(_dataDir + u"workpls.pdf");
}


int main(int argc, char** argv)
{
    try
    {
        auto doc = MakeObject<Document>();
        auto pages = doc->get_Pages();
        pages->Add();
        //Numeration of Pages starts from 1
        auto page = pages->idx_get(1);
        auto paragraps = page->get_Paragraphs();

        paragraps->Add(MakeObject<TextFragment>(u"Кп"));

        auto text1 = MakeObject<TextFragment>(u"Фамилия: <surname>");
        auto ts1 = text1->get_TextState();
        ts1->set_FontSize(16);
        ts1->set_FontStyle(FontStyles::Italic);
        paragraps->Add(text1);

        auto text2 = MakeObject<TextFragment>(u"Имя: <name>");
        auto ts2 = text2->get_TextState();
        ts2->set_FontSize(16);
        ts2->set_FontStyle(FontStyles::Italic);
        paragraps->Add(text2);

        auto text3 = MakeObject<TextFragment>(u"Отчество: <second_name>");
        auto ts3 = text3->get_TextState();
        ts3->set_FontSize(16);
        ts3->set_FontStyle(FontStyles::Italic);
        paragraps->Add(text3);

        auto text4 = MakeObject<TextFragment>(u"Сумма: <summ>");
        auto ts4 = text4->get_TextState();
        ts4->set_FontSize(16);
        ts4->set_FontStyle(FontStyles::Italic);
        paragraps->Add(text4);

        doc->Save(u"workpls.pdf");
        Console::WriteLine(u"Example finished.");

        ReplaceTextOnAllPages(u"<surname>", u"Суворов");
        ReplaceTextOnAllPages(u"<name>", u"Егор");
        ReplaceTextOnAllPages(u"<second_name>", u"плюсы");
        ReplaceTextOnAllPages(u"<summ>", u"1337");

    }
    catch (const System::Exception& error)
    {
        Console::WriteLine(u"Error: {0}", error->get_Message());
        return 1;
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}