/* 
 *  download.c - A simple downloader.
 *
 *  Copyleft 2022   Wanderer XP. 
 *
 *  Fair Warning: I am not a pro at C. So this code might offend you.
 *
 *  This program is free software: you can redistribute it and/or modify it under the terms of the 
 *  GNU General Public License as published by the Free Software Foundation, either version 3 
 *  of the License, or (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 *  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 *  for more details.
 *  
 *  You should have received a copy of the GNU General Public License along with this program. 
 *  If not, see <https://www.gnu.org/licenses/>.
 */ 

#include <stdio.h>
#include <curl/curl.h>

int cleanup_dwnld() {
    fclose(fp);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

int main(int argc, char **argv) {
    CURL *curl;
    FILE *fp;
    int result;

    fp = fopen(argv[2], "wb");

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    result = curl_easy_perform(curl);

    if (result == CURLE_OK)
    {
        printf("Download Successful. File saved as %s.\n", argv[2]);
        
        fclose(fp);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 0;
    }
    else
    {
        printf("Error: %s\n", curl_easy_strerror(result));
        fclose(fp);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }
    

}
