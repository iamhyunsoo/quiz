class Solution {
    var cache: [[Int]: Int] = [:]
    func shoppingOffers(_ price: [Int], _ special: [[Int]], _ needs: [Int]) -> Int {
        return getMinimumCosts(price, special, needs);
    }
    
    private func getMinimumCosts(_ price: [Int], _ special: [[Int]], _ needs: [Int]) -> Int {
        if self.cache.keys.contains(needs) {
            return self.cache[needs]!
        }
        var costs: Int = getCosts(price, needs)
        for offer in special {
            var cp = needs
            var poss: Bool = true
            for i in stride(from: 0, to: cp.count, by: 1) {
                if (cp[i] - offer[i]) < 0 { 
                    poss = false
                    break 
                }
                cp[i] -= offer[i]
            }
            if poss {
                costs = min(costs, offer.last! + getMinimumCosts(price, special, cp))
            }
        }
        self.cache[needs] = costs
        return costs
    }

    private func getCosts(_ price: [Int], _ needs: [Int]) -> Int {
        var total = 0
        for (i, e) in price.enumerated() {
            total += e * needs[i]
        }
        return total
    }
}
