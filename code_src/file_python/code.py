from collections import Counter

def f(s):
    d = Counter(s)  #	dictionrary đếm các chữ xuất hiện bao lần trong xâu s
    dh = {k: d[k] // 2 for k in d} # xâu a= bằng 1 nửa xâu s 

    r = ''
    i = 0
    s = s[::-1] #Đảo ngược xâu thì thấy xâu a nằm trong xâu s
    while len(r) < len(s) // 2:
        m = -1	# m là biến lưu index của s[m] sao cho s[m] nhỏ nhất thỏa mãn 
        while True:
            c = s[i]	# duyệt tất cả phần tử bằng biến i
            if dh[c] > 0 and (m < 0 or c < s[m]):# dh[c]>0 khi kí tự đó xuất hiện trong xâu. Vế sau của and dùng để tìm s[m] min (phần trick)
                
                m = i
                
            d[c] -= 1  #// nếu ko chọn kí tự c thì ktra xem có đủ kí tự c ko
            if d[c] < dh[c]:
                break
            i += 1
        print(m)    
        for j in range(m + 1, i + 1): #khoảng từ m+1 đến I là khoảng xét (ta đã trừ biến đếm đi , giờ tăng lên trả lại)
            d[s[j]] += 1
        dh[s[m]] -= 1	#giảm biến đếm trong trong xâu a
        r += s[m]		#thêm kí tự thỏa mãn ( min, dk d[c]> dh[c]
        i = m + 1		#xét tiếm kí tự tiếp
    return r


s = "bbabba"
print(f(s))