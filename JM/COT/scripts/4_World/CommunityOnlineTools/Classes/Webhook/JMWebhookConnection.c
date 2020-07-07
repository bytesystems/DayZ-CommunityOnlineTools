class JMWebhookConnection: Managed
{
    private RestContext m_Context;

    string Name;
    string ContextURL;
    string Address;

    bool Enabled;

    void Init( RestApi core )
    {
        m_Context = core.GetRestContext( ContextURL );
    }

	void Post( notnull ref JsonSerializer serializer, notnull ref JMWebhookMessage message )
	{
        if ( Enabled )
        {
            string data = message.Prepare( serializer );

            m_Context.SetHeader( "application/json" );
            m_Context.POST( new JMWebhookCallback, Address, data );
        }
	}
};