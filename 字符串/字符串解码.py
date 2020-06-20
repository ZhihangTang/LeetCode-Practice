class pair:
    def __init__(self, k, v):
        self.k = k
        self.v = v


class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        res = ""
        num = 0
        for i in range(len(s)):
            print(res)
            if s[i].isdigit():
                num = int(s[i]) + num * 10
                continue
            if s[i] == "[":
                st.append(pair(num, ""))
                num = 0
                continue
            if s[i] == "]":
                cnt = st[-1].k
                tmp = ""
                while cnt:
                    tmp += st[-1].v
                    cnt -= 1
                st.pop()
                if len(st) == 0:
                    res += tmp
                else:
                    st[-1][1] += tmp
                continue
            if len(st) != 0:
                st[-1].v += s[i]

            else:
                res += s[i]
        return res


if __name__=="__main__":
    a = "3[a]2[bc]"
    s=Solution()
    print(s.decodeString(a))
