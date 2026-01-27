#ifndef __LIBFACTLOG_H__
#define __LIBFACTLOG_H__


/*
 * 參數 : 
 *   filename -> 寫入檔案的名稱，請寫完整路徑，若沒有該檔案會自行創建。
 *   buf -> 要寫入的buf
 *   len -> 要寫入buf的長度
 * 回傳值 :
 *   <= 0 沒寫入任何值，可以判定為寫入失敗
 *   > 0 回傳寫入的量
 * */
int LogWrite(const char *filename, unsigned char *buf, int len);


/*
 * 參數 :
 *   filename -> 讀取檔案的名稱，請寫完整路徑。
 * 回傳值 :
 *   < 0 : 開啟檔案失敗，可能是該檔案不存在
 *   >= 0 : 回傳檔案的size，也有可能是0，代表該檔案存在但是沒有內容
 * */
int GetFileSize(const char *filename);

/*
 * 參數 : 
 *   filename -> 讀取檔案的名稱，請寫完整路徑。
 *   buf -> 要讀取出的buf
 *   len -> 要讀取出buf的長度
 * 回傳值 :
 *   <= 0 沒讀取任何值，可以判定為讀取失敗
 *   > 0 回傳讀取的量
 * */
int LogRead(const char *filename, unsigned char *buf, int len);

#endif
