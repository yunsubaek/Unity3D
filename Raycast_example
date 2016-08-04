//화면의 중앙점(레이캐스트로)에 이벤트 적용.
//태그 비교를 통해
using System;
using UnityEngine;

private RaycastHit hit;
// Update is called once per frame
private void Update()
{
    if (Input.GetMouseButtonDown(0))
    {
        //현재위치,보는곳,바라보는곳의 정보,사정거리,태그비교(해당 태그에만 레이캐스트 적용)
        if (Physics.Raycast(transform.position, transform.forward, out hit, 30.0F, LayerMask.GetMask("Ball")))
        {
            if (hit.collider.tag == "Ball")
            {
                hit.transform.position += transform.forward;
            }
        }
    }
}
