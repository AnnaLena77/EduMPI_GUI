import QtQuick

// Which communicators communicate in the selected second and which ranks take part in them.
// The input is the same data the 3D view draws its arrows from (p2pData, collData); the sidebar
// lists `list`, `filter` is the communicator selected there ("" = all of them).
QtObject {
    id: state

    property var p2pData: null
    property var collData: null
    property string filter: ""

    property var info: ({})            // name -> {name, ranks, bytes, calls}
    property var list: []              // [{name, size, bytes, calls}] for the drop-down
    property var selectedRanks: []     // ranks of the selected communicator
    property bool selectedActive: false

    property string lastKey: ""

    onFilterChanged: apply()

    function apply() {
        if(filter === ""){
            selectedActive = false
            selectedRanks = []
            return
        }
        var e = info[filter]
        selectedRanks = e ? e.ranks : []
        selectedActive = true
    }

    function update() {
        if(!p2pData || !collData) return
        var comms = {}
        function entryFor(name) {
            if(comms[name] === undefined) comms[name] = {name: name, rankSet: {}, bytes: 0, calls: 0}
            return comms[name]
        }
        for(var row = 0; row < p2pData.rowCount(); row++){
            var name = p2pData.simple_data(row, "communicator")
            if(name === "") continue
            var e = entryFor(name)
            var proc = Number(p2pData.simple_data(row, "processrank"))
            var partner = Number(p2pData.simple_data(row, "partnerrank"))
            var sent = Number(p2pData.simple_data(row, "send_size"))
            var recvd = Number(p2pData.simple_data(row, "recv_size"))
            e.calls++
            e.bytes += sent + recvd
            e.rankSet[proc] = true
            if(partner >= 0 && (sent > 0 || recvd > 0)) e.rankSet[partner] = true
        }
        for(var crow = 0; crow < collData.rowCount(); crow++){
            var cname = collData.simple_data(crow, "communicator")
            if(cname === "") continue
            var ce = entryFor(cname)
            ce.calls++
            ce.rankSet[Number(collData.simple_data(crow, "processrank"))] = true
            var cpart = collData.simple_data(crow, "coll_partnerranks")
            if(cpart !== "" && cpart !== undefined){
                if(!(cpart instanceof Array)) cpart = Object.values(cpart)
                for(var q of cpart) ce.rankSet[Number(q)] = true
            }
        }
        var entries = []
        for(var n in comms){
            var ranks = Object.keys(comms[n].rankSet).map(Number).sort(function(x, y){ return x - y })
            comms[n].ranks = ranks
            entries.push({name: n, size: ranks.length, bytes: comms[n].bytes, calls: comms[n].calls})
        }
        // the selected communicator stays in the list in seconds in which it is silent
        if(filter !== "" && comms[filter] === undefined){
            entries.push({name: filter, size: 0, bytes: 0, calls: 0})
        }
        entries.sort(function(x, y){ return (y.size - x.size) || (x.name < y.name ? -1 : 1) })
        info = comms
        // the list is replaced only if it changed, so that an open drop-down is not reset
        var key = JSON.stringify(entries.map(function(c){ return [c.name, c.size] }))
        if(key !== lastKey){
            lastKey = key
            list = entries
        }
        apply()
    }
}
