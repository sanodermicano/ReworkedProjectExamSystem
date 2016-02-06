#include "allHeaders.h"


//input the sound
inline HRESULT BlockForResult(ISpRecoContext * pRecoCtxt, ISpRecoResult ** ppResult) //recording variable and the result
{
	HRESULT hr = S_OK;
	CSpEvent event;

	while (SUCCEEDED(hr) &&
		SUCCEEDED(hr = event.GetFrom(pRecoCtxt)) &&
		hr == S_FALSE)
	{
		hr = pRecoCtxt->WaitForNotifyEvent(INFINITE);
	}

	*ppResult = event.RecoResult();
	if (*ppResult)
	{
		(*ppResult)->AddRef();
	}
	return hr;
}


int voiceRecognition(string Qtext)
{
	HRESULT hr = E_FAIL;
	int word=0;

	CSpDynamicString Qtextout; 
	

	if (SUCCEEDED(hr = ::CoInitialize(NULL)))
	{
		{
			CComPtr<ISpRecoContext> cpRecoCtxt;
			CComPtr<ISpRecoGrammar> cpGrammar;
			CComPtr<ISpVoice> cpVoice;
			hr = cpRecoCtxt.CoCreateInstance(CLSID_SpSharedRecoContext);

			if (SUCCEEDED(hr))
			{
				hr = cpRecoCtxt->GetVoice(&cpVoice);
			}

			if (cpRecoCtxt && cpVoice &&
				SUCCEEDED(hr = cpRecoCtxt->SetNotifyWin32Event()) &&
				SUCCEEDED(hr = cpRecoCtxt->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION))) &&
				SUCCEEDED(hr = cpRecoCtxt->SetAudioOptions(SPAO_RETAIN_AUDIO, NULL, NULL)) &&
				SUCCEEDED(hr = cpRecoCtxt->CreateGrammar(0, &cpGrammar)) &&
				SUCCEEDED(hr = cpGrammar->LoadDictation(NULL, SPLO_STATIC)) &&
				SUCCEEDED(hr = cpGrammar->SetDictationState(SPRS_ACTIVE)))
			{
				USES_CONVERSION;

				CComPtr<ISpRecoResult> cpResult;

				Qtextout.operator=(Qtext.c_str());
				cpVoice->Speak(Qtextout, SPF_ASYNC, NULL);

				if (SUCCEEDED(hr = BlockForResult(cpRecoCtxt, &cpResult)))
				{
					cpGrammar->SetDictationState(SPRS_INACTIVE);

					CSpDynamicString dstrText;

					if (SUCCEEDED(cpResult->GetText(SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE,
						TRUE, &dstrText, NULL)))
					{
						cpResult.Release();
					}
					if (_wcsicmp(dstrText, L"True") == 0)
					{
						word = 1;
						//break;
					}
					if (_wcsicmp(dstrText, L"Two") == 0)
					{
						word = 1;
						//break;
					}
					if (_wcsicmp(dstrText, L"False") == 0)
					{
						word = 2;
						//break;
					}
					if (_wcsicmp(dstrText, L"Falls") == 0)
					{
						word = 2;
						//break;
					}
					if (_wcsicmp(dstrText, L"Follows") == 0)
					{
						word = 2;
						//break;
					}
					if (_wcsicmp(dstrText, L"A") == 0)
					{
						word = 3;
						//break;
					}
					if (_wcsicmp(dstrText, L"Eight") == 0)
					{
						word = 3;
						//break;
					}
					if (_wcsicmp(dstrText, L"B") == 0)
					{
						word = 4;
						//break;
					}
					if (_wcsicmp(dstrText, L"Bee") == 0)
					{
						word = 4;
						//break;
					}
					if (_wcsicmp(dstrText, L"C") == 0)
					{
						word = 5;
						//break;
					}
					if (_wcsicmp(dstrText, L"See") == 0)
					{
						word = 5;
						//break;
					}
					if (_wcsicmp(dstrText, L"Fire") == 0)
					{
						word = 6;
						//break;
					}
					if (_wcsicmp(dstrText, L"Leave") == 0)
					{
						word = 7;
						//break;
					}
					if (_wcsicmp(dstrText, L"Leave it") == 0)
					{
						word = 7;
						//break;
					}
					if (_wcsicmp(dstrText, L"We've") == 0)
					{
						word = 7;
						//break;
					}
					if (_wcsicmp(dstrText, L"Quit") == 0)
					{
						word = 7;
						//break;
					}
					if (_wcsicmp(dstrText, L"Quits") == 0)
					{
						word = 7;
						//break;
					}
					if (_wcsicmp(dstrText, L"Switch") == 0)
					{
						word = 8;
						//break;
					}
					if (_wcsicmp(dstrText, L"Change") == 0)
					{
						word = 8;
						//break;
					}
					
					cout << dstrText.CopyToChar();
					cpGrammar->SetDictationState(SPRS_ACTIVE);
				}
			}
		}
		::CoUninitialize();
	}
	return word;
}

void speak(string Qtext,int sleepTime)
{
	HRESULT hr = E_FAIL;

	CSpDynamicString Qtextout;


	if (SUCCEEDED(hr = ::CoInitialize(NULL)))
	{
		{
			CComPtr<ISpRecoContext> cpRecoCtxt;
			CComPtr<ISpRecoGrammar> cpGrammar;
			CComPtr<ISpVoice> cpVoice;
			hr = cpRecoCtxt.CoCreateInstance(CLSID_SpSharedRecoContext);

			if (SUCCEEDED(hr))
			{
				hr = cpRecoCtxt->GetVoice(&cpVoice);
			}

			if (cpRecoCtxt && cpVoice &&
				SUCCEEDED(hr = cpRecoCtxt->SetNotifyWin32Event()) &&
				SUCCEEDED(hr = cpRecoCtxt->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION))) &&
				SUCCEEDED(hr = cpRecoCtxt->SetAudioOptions(SPAO_RETAIN_AUDIO, NULL, NULL)) &&
				SUCCEEDED(hr = cpRecoCtxt->CreateGrammar(0, &cpGrammar)) &&
				SUCCEEDED(hr = cpGrammar->LoadDictation(NULL, SPLO_STATIC)) &&
				SUCCEEDED(hr = cpGrammar->SetDictationState(SPRS_ACTIVE)))
			{
				USES_CONVERSION;
				CComPtr<ISpRecoResult> cpResult;
				Qtextout.operator=(Qtext.c_str());
				cpVoice->Speak(Qtextout, SPF_ASYNC, NULL);
				Sleep(sleepTime);
			}
		}
		::CoUninitialize();
	}
}