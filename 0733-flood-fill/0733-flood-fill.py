class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        target = image[sr][sc]
        self.fill(image, sr, sc, target, color)
        return image
        
        

    def fill(self, image, sr, sc, target, color):
        if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]): 
            return
        if image[sr][sc] != target:
            return
        image[sr][sc] = color

        self.fill(image, sr + 1, sc, target, color)
        self.fill(image, sr - 1, sc, target, color)
        self.fill(image, sr, sc + 1, target, color)        
        self.fill(image, sr, sc - 1, target, color)