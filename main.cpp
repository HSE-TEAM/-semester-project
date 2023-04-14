#include <exception>

#include "system/codeporting_translator_cs2cpp_framework.h"
#include "system/console.h"

#include "Aspose.PDF.Cpp/Text/TextFragmentAbsorber.h"
#include "Aspose.PDF.Cpp/Document.h"

#include "Aspose.PDF.Cpp/Text/FontRepository.h"
#include "Aspose.PDF.Cpp/PageCollection.h"

#include "Aspose.PDF.Cpp/Text/FontStyles.h"
#include "Aspose.PDF.Cpp/Text/TextFragment.h"
#include "Aspose.PDF.Cpp/Text/TextFragmentCollection.h"
#include "Aspose.PDF.Cpp/Text/TextFragmentState.h"

using namespace System;
using namespace Aspose::Pdf;
using namespace Aspose::Pdf::Text;

void ReplaceTextOnAllPages(System::String phrase_to_change, System::String changed_phrase, bool is_first_call) {

    String _dataDir(u"E:\\g-soh\\Project1\\Project1\\");
    if (is_first_call) {
        auto document = MakeObject<Document>(_dataDir + u"workpls.pdf");

        auto textFragmentAbsorber = MakeObject<TextFragmentAbsorber>(phrase_to_change);
        document->get_Pages()->Accept(textFragmentAbsorber);
        auto textFragmentCollection = textFragmentAbsorber->get_TextFragments();



        for (auto textFragment : textFragmentCollection) {
            textFragment->set_Text(changed_phrase);
            textFragment->get_TextState()->set_Font(FontRepository::FindFont(u"Verdana"));
            textFragment->get_TextState()->set_FontSize(12);
        }

        document->Save(_dataDir + u"workpls1.pdf");
    }
    else {
        auto document = MakeObject<Document>(_dataDir + u"workpls1.pdf");

        auto textFragmentAbsorber = MakeObject<TextFragmentAbsorber>(phrase_to_change);
        document->get_Pages()->Accept(textFragmentAbsorber);
        auto textFragmentCollection = textFragmentAbsorber->get_TextFragments();



        for (auto textFragment : textFragmentCollection) {
            textFragment->set_Text(changed_phrase);
            textFragment->get_TextState()->set_Font(FontRepository::FindFont(u"Verdana"));
            textFragment->get_TextState()->set_FontSize(12);
        }

        document->Save(_dataDir + u"workpls1.pdf");
    }
   
}

int main(int argc, char** argv)
{
    try
    {
        ReplaceTextOnAllPages(u"модуль", u"кОмпик", true);
        ReplaceTextOnAllPages(u"Следствия", u"экспонента", false);
        ReplaceTextOnAllPages(u"<second_name>", u"плюсы", false);
        ReplaceTextOnAllPages(u"<summ>", u"1337", false);

    }
    catch (const System::Exception& error)
    {
        Console::WriteLine(u"Error: {0}", error->get_Message());
        return 1;
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << '/n';
        return 1;
    }

    return 0;
}
