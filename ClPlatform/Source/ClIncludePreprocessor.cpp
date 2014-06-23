#include "ClIncludePreprocessor.hpp"
#include "ClError.hpp"
#include "logs.hpp"

shared_ptr<std::string> ClIncludePreprocessor::replaceIncludes( shared_ptr<std::string> source,
                                                                     std::set<std::string>& includeDirectories )
{
    std::stringstream output;
    std::istringstream sourceStream( *source );

    std::string line;

    while ( std::getline( sourceStream, line) ) 
    {
        if ( isLineIncludeDirective(line) )
        { 
            std::string includeFilename = getIncludeFilename(line);
            std::string includeFilePath = getIncludeFilePath(includeFilename, includeDirectories);

            if ( includedFilePaths.find(includeFilePath) == includedFilePaths.end() )
            {
                includedFilePaths.insert(includeFilePath);
                shared_ptr<std::string> includeText = readFile(includeFilePath);
                std::string textWithReplacedIncludes = *replaceIncludes(includeText, includeDirectories);
                output << textWithReplacedIncludes;
            }
        }
        else
        {
            output << line << std::endl;
        }
    }

    return make_shared<std::string>(output.str());
}

std::string ClIncludePreprocessor::getIncludeFilePath(std::string& includeFilename, 
                                                      std::set<std::string>& includeDirectories)
{
    ifstream input;
    for(set<string>::iterator i=includeDirectories.begin(); i!= includeDirectories.end(); i++)
	{
        std::ostringstream fileNameStream;
        fileNameStream << (*i) << "/" << includeFilename;
        string fileName = fileNameStream.str();
        input.open( fileName.c_str() , std::ios::in);
        if( input.is_open() )
            return fileName;
	}

    ERROR << "file " << includeFilename << " not found in include directories!";
    throw FILE_READ_ERROR;
}

std::string ClIncludePreprocessor::getIncludeFilename( std::string& line ) // TODO - refactor
{
    int i=8;
    while(line[i] != '"') i++;
    char includeFileName[100];
    i++;
    int j=0;
    while(line[i] != '"')
    {
        includeFileName[j] = line[i];
        i++; j++;
    }
    includeFileName[j] = 0;
    return std::string(includeFileName);
}

bool ClIncludePreprocessor::isLineIncludeDirective( std::string& line ) // TODO - refactor
{
    return (line.size()>7)&&(line[0] == '#')&&(line[1]=='i')&&(line[2]=='n')&&(line[3]=='c')&&(line[4]=='l')&&(line[5]=='u')&&(line[6]=='d')&&(line[7]=='e');
}

shared_ptr<std::string> ClIncludePreprocessor::readFile(std::string& filename) // TODO the same code is in class ClKernelFromSourceLoader, remove this COPY-PASTE
{
    std::ifstream file(filename);
    if ( !file.is_open() ) 
    {
        ERROR << "error while reading file " << filename;
        throw FILE_READ_ERROR;
    }

    auto text = make_shared<std::string>();

    file.seekg(0, std::ios::end);   
    text->reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    text->assign( std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>() );

    return text;
}

