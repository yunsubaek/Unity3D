public class test : UIBase
{
    public override void OnOpened()
    {
        DataBinder = GlobalData.ProfileData.DataBinder;
        GlobalData.ProfileData.NickName = "수정!";
    }

    public override void OnClosed()
    {
    }
}

//ProfileData에 미리 프로퍼티를 만들어서 접근.
