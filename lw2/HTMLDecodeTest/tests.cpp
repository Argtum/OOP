#include "pch.h"
#include "lw2/HTMLDecode/HtmlDecoder.h"

TEST_CASE("ReplaceHtmlEntity - funcrion must return new string without HTML entitys")
{
	string inputStr, outputStr, htmlEntity;

	inputStr = "&quot;Meow&quot;";
	outputStr = "\"Meow\"";
	htmlEntity = "&quot;";

	CHECK(outputStr == GetReplaceHtmlEntity(inputStr, htmlEntity));
}