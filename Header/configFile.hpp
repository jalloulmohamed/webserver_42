#ifndef CONFIG_FILE
#define CONFIG_FILE



class configFile
{
    private:
        char *file;
        bool valid_file;

        
    public:
        configFile();
        ~configFile();
        configFile(char *file,bool valid_file);
        bool validefile();
        void parsing();
};
#endif