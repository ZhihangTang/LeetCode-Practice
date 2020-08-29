def KMP_algorithm(string, substring):
    '''
    KMP字符串匹配的主函数
    若存在字串返回字串在字符串中开始的位置下标，或者返回-1
    '''
    pnext = gen_pnext(substring)
    n = len(string)
    m = len(substring)
    i, j = 0, 0
    while (i < n) and (j < m):
        if (string[i] == substring[j]):
            i += 1
            j += 1
        elif (j != 0):
            j = pnext[j - 1]
        else:
            i += 1
    if (j == m):
        return i - j
    else:
        return -1


def gen_pnext(substring):
    """
    构造临时数组pnext
    """
    index, m = 0, len(substring)
    pnext = [0] * m
    i = 1
    while i < m:
        if (substring[i] == substring[index]):
            pnext[i] = index + 1
            index += 1
            i += 1
        elif (index != 0):
            index = pnext[index - 1]
        else:
            pnext[i] = 0
            i += 1
    return pnext


if __name__ == "__main__":
    string = 'abcxabcdabcdabcy'
    substring = 'abcdabcy'
    out = KMP_algorithm(string, substring)
    print(out)

'''
模式串：ABCABEABCABD
子串	ABCABD
KMP算法的精髓主要是在计算匹配表
通过对子串前n位分别计算匹配值
即其所对应的前缀集和后缀集最长相等的长度
对于
ABCABD
A 	    无前缀，无后缀，匹配值0
AB 	    前缀{A}，后缀{B}匹配值0
ABC	    前缀{A，AB}后缀{BC，B}匹配值0
ABCA	前缀{A，AB，ABC}后缀{BCA，CA，A}匹配值1
ABCAB	前缀{A，AB，ABC，ABCA}后缀{BCAB，CAB，AB，B}匹配值2
ABCABD	前缀{A，AB，ABC，ABCAB}后缀{BCABD，CABD，ABD，BD，D}匹配值0
因此匹配表为[0,0,1,2,0]
'''