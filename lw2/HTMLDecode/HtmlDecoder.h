#pragma once

void replaceHtmlEntity(std::string& html, const std::string& htmlEntity);
void HtmlDecode(std::string& html);

std::string GetReplaceHtmlEntity(std::string& html, const std::string& htmlEntity);
std::string GetHtmlDecode(std::string& html);
