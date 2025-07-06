class MinStack:

    def __init__(self):
        self.st=[]

    def push(self, val: int) -> None:
        if not self.st:
            self.st.append([val,val])
        else:
            self.st.append([val,min(self.st[-1][1],val)])

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0]

    def getMin(self) -> int:
        return self.st[-1][1]

#optimal approach
class MinStack:
    
    def __init__(self):
        self.st=[]
        self.mini=1e9

    def push(self, val: int) -> None:
        if not self.st:
            self.st.append(val)
            self.mini=val
        else:
            if val<self.mini:
                self.st.append(2*val-self.mini)
                self.mini=val
            else:
                self.st.append(val)

    def pop(self) -> None:
        if self.st[-1]<self.mini:
            self.mini=2*self.mini-self.st[-1]
            self.st.pop()
        else: self.st.pop()

    def top(self) -> int:
        if self.st[-1]<self.mini: return self.mini
        return self.st[-1]

    def getMin(self) -> int:
        return self.mini