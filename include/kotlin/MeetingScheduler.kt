class Solution {
    fun minAvailableDuration(slots1: Array<IntArray>, slots2: Array<IntArray>, duration: Int): List<Int> {
        val que = PriorityQueue<IntArray> { slot1, slot2 -> slot1[0] - slot2[0] }
        for (slot in slots1) {
            if (slot[1] - slot[0] >= duration) {
                que.offer(slot)
            } 
        }
        for (slot in slots2) {
            if (slot[1] - slot[0] >= duration) {
                que.offer(slot)
            } 
        }
        
        while (que.size > 1) {
            val s1 = que.poll()
            val s2 = que.peek()
            
            if (s1[1] >= s2[0] + duration) {
                return listOf<Int>(s2[0], s2[0] + duration)
            }
        }
        val other: List<Int> = emptyList()
        return other; 
    }
}
