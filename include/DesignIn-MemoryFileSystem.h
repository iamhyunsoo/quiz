class File
{
public:
    std::unordered_map<std::string, File*> mFiles;
    std::vector<std::string> mDirs;
    std::string mContent = "";
};

class FileSystem {
    File* mRoot;
public:
    FileSystem() 
    {
        mRoot = new File();    
    }
    
    vector<string> ls(string path) 
    {
        auto file = this->getFile(path);
        if (file->mContent != "")
        {
            return {path.substr(path.find_last_of('/') + 1)};
        }
        std::sort(file->mDirs.begin(), file->mDirs.end());
        return file->mDirs;
    }
    
    void mkdir(string path) 
    {
        this->getFile(path);
    }

    void addContentToFile(string filePath, string content) 
    {
        auto file = this->getFile(filePath);
        file->mContent += std::move(content);
    }

    string readContentFromFile(string filePath) 
    {
        auto file = this->getFile(filePath);
        return file->mContent;
    }
    
private:
    File* getFile(string& path)
    {
        std::istringstream s(path);
        std::string curFile = "";
        File* file = mRoot;
        
        while (std::getline(s, curFile, '/'))
        {
            if (file->mFiles[curFile] == nullptr)
            {
                file->mFiles[curFile] = new File(); 
                file->mDirs.push_back(curFile);
            }
            file = file->mFiles[curFile];
        }
        return file;
    }

};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
