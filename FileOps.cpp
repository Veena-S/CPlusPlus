#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>

int main()
{
    

    auto start = std::chrono::system_clock::now();
   // std::cout << start.time_since_epoch();
    
    std::time_t t = std::time(nullptr);
 /*   std::string tz = "TZ=Asia/Singapore";
    _putenv(tz.data());*/

    std::tm* re = std::localtime(&t);
    

    std::cout << re->tm_hour <<"::" << re->tm_min << "::" << re->tm_sec << std::endl;
    std::cout << "Singapore: " << std::put_time(std::localtime(&t), "%c %Z") << '\n';

    
    std::stringstream sstream;
    //sstream << std::put_time(std::localtime(&t), "%c %Z");
    sstream << std::put_time(std::localtime(&t), "%F %X");

    std::string strDate;
    sstream >> strDate;

    std::string strTime;
    sstream >> strTime;
    std::string strNewTime = strTime;
    
    //std::replace_if(strNewTime.begin(), strNewTime.end(), [](char c) { return (c == ':'); }, '-');
    
    std::replace(strNewTime.begin(), strNewTime.end(), ':', '-');
    
    //std::replace_copy_if(strTime.begin(), strTime.end(), strNewTime.begin(), [](char c) { return (c == ':'); }, '-');
    //std::replace_copy(strTime.begin(), strTime.end(), strNewTime.begin(), ':', '-');

    if (strNewTime.empty())
    {
        std::cout << "New time is empty;";
    }

    std::cout << strDate << std::endl;
    std::cout << strTime << std::endl;
    std::cout << strNewTime << std::endl;
    std::string str = strNewTime;
    std::cout << str;

    std::cin.get();
    return 0;

   // strTime = std::to_string(re->tm_hour) + "_" +
   //     std::to_string(re->tm_min) + "_" +
   //     std::to_string(re->tm_sec);
   //strDate = std::to_string(re->tm_mday) + "_" +
   //     std::to_string(re->tm_mon) + "_" +
   //     std::to_string(re->tm_year+1900);

   //std::cout << strDate << std::endl;
   //std::cout << strTime << std::endl;
    
    std::string strOutputFile = "Test_" + strDate+ "_"+ strTime + ".log";

    std::string strInputFile = "Test.log";

    // Rename the existing file.
    if (0 == std::rename(strInputFile.c_str(), strOutputFile.c_str()))
    {
        std::cout << "File successfully renamed: " << strOutputFile << std::endl;
    }
    else
    {
        std::cout << "File successfully failed. No file with name: " << strInputFile << std::endl;
    }

    // By copying the contents of the old file new file.

    char* pContents = NULL;
    std::streamsize nSize = 0;
    
    std::ifstream ifFile(strInputFile);
    std::ofstream ofFile(strOutputFile);
    /*std::fstream ofFile;
    ofFile.open(strOutputFile, std::fstream::out);*/
    if (ifFile)
    {
        std::streambuf* pBuffer = ifFile.rdbuf();
        
        nSize = pBuffer->pubseekoff(0, ifFile.end);
        pBuffer->pubseekoff(0, ifFile.beg);

        pContents = new char[nSize];
        pBuffer->sgetn(pContents, nSize);
        ifFile.close();

        std::cout.write(pContents, 10);
    }

    if (ofFile.is_open())
    {
        std::streambuf* pOutBuffer = ofFile.rdbuf();

        pOutBuffer->sputn(pContents, nSize);
        ofFile.close();
    }

    std::cin.get();
    return 0;

   
}
