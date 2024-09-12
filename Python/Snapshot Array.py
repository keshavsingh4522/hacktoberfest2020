class SnapshotArray:

   def __init__(self, length: int):
       self.snapShot = {}
       self.snapCount = 0
       

   def set(self, index: int, val: int) -> None:
       self.snapShot[(self.snapCount, index)] = val
       

   def snap(self) -> int:
       self.snapCount += 1
       return self.snapCount -1
       

   def get(self, index: int, snap_id: int) -> int:
       for snapId in range(snap_id, -1, -1):
           if (snapId, index) in self.snapShot:
               return self.snapShot[(snapId, index)]
       return 0
